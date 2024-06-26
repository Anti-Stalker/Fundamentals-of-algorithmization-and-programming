from django.contrib import admin
from .models import Category, Word

# Register your models here.
admin.site.register(Category)

@admin.register(Word)
class WordAdmin(admin.ModelAdmin):
    search_fields = ('text', )