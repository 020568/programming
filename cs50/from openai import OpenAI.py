from openai import OpenAI

client = OpenAI(api_key="sk-XshIiEwUP10afv6Yvjo0PBuFG0ZhihfMR03gd4mDAZu9DUwU")
response = client.responses.create(
    input = "In one sentence, what is the CS50?",
    model = "gpt-4"
)
print(response.output.text)
