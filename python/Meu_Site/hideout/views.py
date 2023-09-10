from django.shortcuts import render
import os

appname="hideout"

routes=[]

templates=os.scandir(os.getcwd()+f"/{appname}/templates/myhtml")
#cria um iterável de objetos que correspondem a referências a ficheiros dentro do diretório. Este referencia todas as templates desta app

for i in templates:
    if(i.name[:-5] not in ["main","horny"]):
        routes.append(i.name[:-5])


#remove os 5 caracteres correspondentes à extensão de ficheiro ".html". Quero fazer com que, nesta aplicação, os nomes dos links correspondam aos nomes das templates sem ser a
#extensão, concatenando depois "main/", que é a subrota principal desta aplicação. Adiciona cada uma das strings a uma lista chamada "routes". Exclui especificamente a main.html de ser acres-
#centada, pois causa comportamento estranho

hornyphotos=os.scandir(os.getcwd()+f'/staticfiles/{appname}/horny/photo')
hornyvideos=os.scandir(os.getcwd()+f'/staticfiles/{appname}/horny/video')
mainvideos=os.scandir(os.getcwd()+f'/staticfiles/{appname}/mainstuff/video')

#A mesma coisa que templates. Só que com:
# -as fotos a serem apresentadas pelo html "horny.html"
# -os videos a serem apresentados pelo htm "main.html"
# da app "default"
hornyphotolist=[]
mainvideolist=[]

def createMediaLists():

    for i in hornyphotos:
        hornyphotolist.append(i.name)
    for i in mainvideos:
        mainvideolist.append(i.name)

createMediaLists()

for i in hornyphotolist:
    print(i)
#utiliza o iterador para percorrer todos os ficheiros do folder e adiciona-os , um por um a uma lista chamada "filenamelist"

def mainPage(request):
    return render(request, "myhtml/main.html",{

        "list":routes,'coolvideos':mainvideolist
    })

#A lista "routes" é utilizada como contexto para o html principal desta app para que a lista de links seja construída na template "main.html"

def selectPage(request,pagename):

    return render(request,f"myhtml/{pagename.lower()}.html",{
        'photos':hornyphotolist,'coolvideos':mainvideolist
        })

#A lista de nomes de ficheiros de fotos é dada como contexto, apenas se a página for horny. Vai alimentar o loop na template
#Que vai apresentar as fotos na pagina como objetos do tipo img





