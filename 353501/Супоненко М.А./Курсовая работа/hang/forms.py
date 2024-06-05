from dataclasses import fields
from pyexpat import model
from django.forms import ModelForm
from .models import Category, Word

class CategoryForm(ModelForm):
    class Meta:
        model = Category
        # fields = ['name']
        fields = '__all__'

class WordForm(ModelForm):
    class Meta:
        model = Word
        # fields = ['text', 'category']
        fields = '__all__'

word_form = WordForm()

category_form = CategoryForm()

