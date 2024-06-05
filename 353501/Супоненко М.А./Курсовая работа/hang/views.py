from multiprocessing import context
from django.views.generic import TemplateView
from django.views.generic.detail import DetailView
# from django.views import View # This was used in the docs, both work
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from .models import Word, Category
from .forms import WordForm, CategoryForm
from random import random
from django.urls import reverse
from .myrandom import MersenneTwister
from .analysisrus import russian_alphabet_frequency_analysis
from .search import kmp_search
from .MiddleSquareMethod import MiddleSquareMethod



class HomeView(TemplateView):
    template_name = "hang/home.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        categories_with_words = Category.objects.filter(word__isnull=False).distinct()
        context['categories_with_words'] = categories_with_words
        return context


class WordsView(TemplateView):
    template_name = "words"
    form_class = WordForm

    def get(self, request, *args, **kwargs):
        words = Word.objects.all()
        form = WordForm()
        context = { 'words_list': words, 'form': form }
        return render(request, 'hang/words.html', context)

    def post(self, request, *args, **kwargs):
        form = self.form_class(request.POST)
        
        if form.is_valid():
            word = form.save()

            word.text = word.text.lower()
            word.save()

            return HttpResponseRedirect(reverse('hang:words'))


class CategoriesView(TemplateView):
    template_name = "categories"
    form_class = CategoryForm

    def get(self, request, *args, **kwargs):
        categories = Category.objects.all()
        form = CategoryForm()
        context = {'form': form, 'categories': categories}
        return render(request, 'hang/categories.html', context)
    
    def post(self, request, *args, **kwargs):
        # form = CategoryForm(request.POST)
        form = self.form_class(request.POST)


        if form.is_valid():
            category = form.save()
            category.name = category.name.lower()
            category.save()
            return HttpResponseRedirect(reverse('hang:categories'))


class WordDeleteView(DetailView):
    template_name = "word-delete"
    form_class = WordForm

    def get(self, request, *args, **kwargs):
        word = Word.objects.get(id=kwargs["id"])
        context = {'word': word}
        return render(request, 'hang/word-delete.html', context)

    def post(self, request, *args, **kwargs):
        form = self.form_class(request.POST)
        if form.is_valid:
            word = Word.objects.get(id=kwargs["id"])
            word.delete()
            return HttpResponseRedirect(reverse('hang:words'))


class CategoryDeleteView(DetailView):
    template_name = "category-delete"
    form_class = CategoryForm

    def get(self, request, *args, **kwargs):
        category = Category.objects.get(id=kwargs["id"])
        context = {'category': category}
        return render(request, 'hang/category-delete.html', context)
    
    def post(self, request, *args, **kwargs):
        form = self.form_class(request.POST)
        if form.is_valid:
            category = Category.objects.get(id=kwargs["id"])
            category.delete()
            return HttpResponseRedirect(reverse('hang:categories'))


class CategoryEditView(DetailView):
    template_name = "category-edit"
    form_class = CategoryForm

    def get(self, request, *args, **kwargs):
        category = Category.objects.get(id=kwargs["id"])
        form = self.form_class(instance=category)
        context = {'form': form}
        return render(request, 'hang/category-edit.html', context)
    
    def post(self, request, *args, **kwargs):
        category = Category.objects.get(id=kwargs["id"])
        form = self.form_class(request.POST, instance=category)
        if form.is_valid:
            category = form.save()
            category.name = category.name.lower()
            category.save()
            return HttpResponseRedirect(reverse('hang:categories'))           


class WordEditView(DetailView):
    template_name = "word-edit"
    form_class = WordForm

    def get(self, request, *args, **kwargs):
        word = Word.objects.get(id=kwargs["id"])
        form = self.form_class(instance=word)
        context = {'form': form}
        return render(request, 'hang/word-edit.html', context)
    
    def post(self, request, *args, **kwargs):
        word = Word.objects.get(id=kwargs["id"])
        form = self.form_class(request.POST, instance=word)
        if form.is_valid:
            word = form.save()
            word.text = word.text.lower()
            word.save()

            return HttpResponseRedirect(reverse('hang:words'))            

def generate_random_numbers(request):
    num = round(random() * 100)
    context = {'random_numbers': num}
    return render(request, 'hang/num.html', context)

def search_words(request):
    if request.method == "POST":
        query = request.POST.get('query', '')
        words = Word.objects.all()
        matches = []
        for word in words:
            word_text = word.text.lower()
            word_matches = kmp_search(word_text, query.lower())
            if word_matches:
                matches.append(word)
        context = {
            'matches': matches,
            'query': query
        }
        return render(request, "admin.html", context)
    else:
        return render(request, "admin.html", {})
    

# class WordVie(DetailView):
#     template_name = "word-picked"
    
#     def get(self, request, *args, **kwargs):
#         words = Word.objects.filter(category=kwargs["id"])
#         random_word = random.choice(words)
#         context = {'random_word': random_word}
#         return render(request, 'hang/word.html', context)
    

class WordView(DetailView):
    template_name = "word-picked"
    
    def get(self, request, *args, **kwargs):
        words = Word.objects.filter(category=kwargs["id"])
        # Инициализируем MersenneTwister с seed, например, текущим временем
        mt = MersenneTwister(seed=None)
        # Получаем случайное слово, используя MersenneTwister
        random_word = words[mt.extract_number() % len(words)]
        context = {'random_word': random_word}
        return render(request, 'hang/word.html', context)

def index(request):
    return render(request, 'hang/index.html')

def word_frequency_view(request):
    # Вызываем функцию частотного анализа для слов из базы данных
    sorted_frequency = russian_alphabet_frequency_analysis()

    # Передаем результаты частотного анализа в шаблон для отображения
    context = {
        'sorted_frequency': sorted_frequency
    }

    return render(request, 'hang/analysisrus.html', context)


def generate_random_number(request):
    rng = MiddleSquareMethod(seed=random())
    random_numbers = rng.generate(1)
    context = {'random_numbers': random_numbers}
    return render(request, 'hang/num.html', context)
