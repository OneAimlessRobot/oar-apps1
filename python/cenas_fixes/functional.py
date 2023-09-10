

def identifier(f,name):
    def wrapper(name):
        f(name)
    return wrapper


@identifier
def greetings(name):
    print(f"Hello there,{name}")

    