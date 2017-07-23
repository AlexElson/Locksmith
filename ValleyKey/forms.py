from django import forms

class AppForm(forms.Form):
    app1 = forms.BooleanField(
        required = False,
        initial = False,
        label = 'X/O Unchecked/Checked'
    )
    app2 = forms.IntegerField(error_messages={
        "required": "This value cannot be empty.",
        "invalid": "Please enter a valid number.",
    })
