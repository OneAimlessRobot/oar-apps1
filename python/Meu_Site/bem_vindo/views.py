from django.http import HttpRequest, HttpResponse
from django.shortcuts import render

# Create your views here.

def greet(request,user):
    return HttpResponse(f"Ola, {user}!")

def sum(request,i,j):
    return HttpResponse(f"soma={i+j}")

def initialView(request):
    return HttpResponse("Olá, visitante.")

