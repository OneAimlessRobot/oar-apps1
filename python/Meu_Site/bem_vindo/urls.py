from django.urls import path
from . import views

urlpatterns=[
    path("<str:user>",views.greet),
    path("<int:i> + <int:j>",views.sum),
    path("",views.initialView)
    ]
