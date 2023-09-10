from django.urls import path
from . import views

urlpatterns =[
    path("",views.mainPage, name="hideout"),
    path("<str:pagename>",views.selectPage)
]