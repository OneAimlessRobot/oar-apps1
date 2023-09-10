from django import forms
from django.shortcuts import render

class VentingInputField(forms.Form):
    mensagem=forms.TextField()


def register(request):
    if request.method=="POST":
        form= VentingInputField(request.POST)
        if form.is_valid():
            novoDesabafo = form.cleaned_data["mensagem"]
            request.session["desabafos"]+=[novoDesabafo]
        else:
            return render(request,"add.html",{"form":form})

    return render(request,"add.html",{"form":VentingInputField()})


def index(request):
    if "desabafos" not in request.session:
        request.session["desabafos"]=[]
    return render(request,"list.html",{"desabafos":request.session["desabafos"]})