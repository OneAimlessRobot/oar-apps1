from django.shortcuts import render
from django.http import HttpRequest

def default(request):
    return render(request,"default/default.html")