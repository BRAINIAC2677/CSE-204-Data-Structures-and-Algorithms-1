class EmptyStackException(Exception):
    def __init__(self):
        super().__init__("EmptyStackException")
