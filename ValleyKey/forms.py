from django import forms

class AppForm(forms.Form):
    submit = forms.BooleanField(
        required = False,
        initial = False,
        label = 'X/O Unchecked/Checked'
    )
    num = forms.IntegerField(error_messages={
        "required": "This value cannot be empty.",
        "invalid": "Please enter a valid number.",
    })
