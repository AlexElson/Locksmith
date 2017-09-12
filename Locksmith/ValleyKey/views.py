from django.shortcuts import render

from django.http import HttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt

from .models import *
from .forms import *



def index(request):

    if request.method == 'POST':
        form = AppForm(request.POST)

        if form.is_valid():
            submit = form.cleaned_data['submit']
            num = form.cleaned_data['num']

            if (num <=0):
                #raise ValidationError("Must be over 0")
                for n in range(num,0):
                    Info.objects.filter(info=submit).delete()
                form = AppForm()
            else:
                for n in range(0,num):
                    suggest = Info(info=submit)
                    suggest.save()
                form = AppForm()
        else:
            submit = ""
    else:
        form = AppForm()
        submit = ""

    first_bar = Info.objects.all().filter(info=0)
    second_bar = Info.objects.filter(info=1)
    context = {
        'title':"Valley Lock and Safe | Chico, CA",
        'first': first_bar,
        'second': second_bar,
        'form':form,
        'submit':submit
        }
    return render(request,'home.html', context)


    #return HttpResponse("Hello, world. You're at the polls index.")


'''    if request.method == 'POST':
        form = SuggestionForm(request.POST)

        # check whether it's valid:
        if form.is_valid():
            submit = form.cleaned_data['suggestion']
            num = form.cleaned_data['number']
            if (num <=0):
                #raise ValidationError("Must be over 0")
                for n in range(num,0):
                    Suggestion.objects.filter(suggestion=submit).delete()
                form = SuggestionForm()
            else:
                for n in range(0,num):
                    suggest = Suggestion(suggestion=submit)
                    suggest.save()
                form = SuggestionForm()
        else:
            submit = ""
    else:
        form = SuggestionForm()
        submit = ""
    first_bar = Suggestion.objects.all().filter(suggestion=0)
    second_bar = Suggestion.objects.filter(suggestion=1)
    context = {
        'title':"Home",
        'first': first_bar,
        'second': second_bar,
        'form':form,
        'submit':submit
        }
    return render(request,'home.html',context)

@csrf_exempt
def suggestions(request):
    if request.method == 'GET':
        suggestions = Suggestion.objects.all()
        suggest = {}
        suggest['suggestions']=[]
        for suggestion in suggestions:
            suggest['suggestions']+=[{
                'id':suggestion.id,
                'suggestion': suggestion.suggestion
                }]
        return JsonResponse(suggest)
    if request.method == 'POST':
        return HttpResponse("POST successful")
    return HttpResponse("404")
        # { 'suggestions':[
        #     {'id': id, 'suggestion': suggestion}
		# ]
		# }
        '''
