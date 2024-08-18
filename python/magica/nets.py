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
    
# ******************LOSSES***********************
def cross_entropy_loss(true, preds):
    log_preds = np.log(preds + 1e-7)  # To handle zeros and prevent log(0)
    
    if len(true.shape) == 1:
        # Integer labels case
        return -np.mean(log_preds[np.arange(len(preds)), true])
    
    # One-hot encoded labels case
    return -np.mean(np.sum(true * log_preds, axis=1))