import numpy as np

class Linear:
    def __init__(self, n_inputs, n_neurons, random_state=42):
        np.random.seed(random_state)
        self.weights = np.random.randn(n_neurons, n_inputs)
        self.bias = np.random.randn(n_neurons)
        
    def __call__(self, inputs):
        return self.forward(inputs)
        
    def forward(self, inputs):
        out = np.dot(inputs, self.weights.T) + self.bias
        
        return out