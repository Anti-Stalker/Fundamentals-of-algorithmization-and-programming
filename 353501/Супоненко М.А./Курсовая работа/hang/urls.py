from django.urls import path
from .views import (
    HomeView, WordsView, CategoriesView,
    WordDeleteView, CategoryDeleteView, CategoryEditView,
    WordEditView, WordView, word_frequency_view, generate_random_number,
)

app_name = 'hang'

urlpatterns = [
    path('', HomeView.as_view(), name='home'),
    path('words/', WordsView.as_view(), name='words'),
    path('MiddleSquareMethod/', generate_random_number, name='generate_random_numbers'),
    path('word-frequency/', word_frequency_view, name='word_frequency'), 
    path('categories/', CategoriesView.as_view(), name='categories'),
    path('words/<int:id>/delete/', WordDeleteView.as_view(), name='word_delete'),
    path('categories/<int:id>/delete/', CategoryDeleteView.as_view(), name='category_delete'),
    path('categories/<int:id>/edit/', CategoryEditView.as_view(), name='category_edit'),
    path('words/<int:id>/edit/', WordEditView.as_view(), name='word_edit'),
    path('category/<int:id>', WordView.as_view(), name='word_view'),
]
