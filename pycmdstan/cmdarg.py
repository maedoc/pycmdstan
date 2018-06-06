class Arg:
    def __init__(self, name, doc, default):
        self.name = name
        self.doc = doc
        self.default = default
        
    
class Choice(Arg):
    def __init__(self, name, doc, choices, default):
        super().__init__(name, doc, default)
        self.choices = choices
        
        
class Value(Arg):
    def __init__(self, name, doc, valid_expr, default):
        super().__init__(name, doc, default)
        self.valid_expr = valid_expr


