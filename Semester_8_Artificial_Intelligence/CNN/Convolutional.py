import numpy as np

# =============================================================================
# Convolutional Forward
# =============================================================================

def zero_pad(X, pad):
        '''
        pad -- a integer
        X -- python numpy array of shape (m, n_H, n_W, n_C)
        X_pad -- padded image of shape (m, n_H + 2*pad, n_W + 2*pad, n_C)
        '''
        X_pad = np.pad(X, ((0, 0), (pad, pad), (pad, pad), (0, 0))
                       , 'constant', constant_values=0)
        return X_pad

# def conv_relu(X_prev, mode = "normal"):
#     '''
#     X_prev --     (m, n_H_prev, n_W_prev, n_C_prev)
#     X -- (m, n_H_prev, n_W_prev, n_C_prev)
#     '''
    
#     cache = X_prev.copy()
    
#     if mode == "normal":
#         X=np.maximum(0,X_prev)
#     else:
#         X=np.maximum(0.1*X_prev,X_prev)
    
#     return X, cache
    
def conv_single_step(x_step, W, b):
        '''
        X_step -- previous X_step      (f, f, n_C_prev)
        W -- matrix of shape (f, f, n_C_prev)
        b -- matrix of shape (1, 1, 1)
        Z -- scaler
        '''
        s = np.multiply(x_step, W)
        Z = np.sum(s)
        Z = Z + float(b)
        return Z
    
def conv_forward(X_prev, W, b, hparameters):
    """
    X_prev --     (m, n_H_prev, n_W_prev, n_C_prev)
    W -- Weights, (f, f, n_C_prev, n_C)
    b -- Biases,  (1, 1, 1, n_C)
    hparameters -- python dictionary containing "stride" and "pad"   
    Returns:
    Z -- conv output, (m, n_H, n_W, n_C)
    cache -- cache of values needed for the conv_backward() function
    """
    # Retrieve dimensions from A_prev's shape (≈1 line)
    
    (m, n_H_prev, n_W_prev, n_C_prev) = X_prev.shape
    
    # Retrieve dimensions from W's shape (≈1 line)
    (f, f, n_C_prev, n_C) = W.shape
    
    # Retrieve information from "hparameters" (≈2 lines)
    stride = hparameters['stride']
    pad = hparameters['pad']
    
    # Compute the dimensions of the CONV output volume using the formula given above. Hint: use int() to floor. (≈2 lines)
    n_H = int((n_H_prev - f + 2 * pad) / stride) + 1
    n_W = int((n_W_prev - f + 2 * pad) / stride) + 1
    
    # Initialize the output volume Z with zeros. (≈1 line)
    Z = np.zeros((m, n_H, n_W, n_C))
    
    # Create A_prev_pad by padding A_prev
    X_prev_pad = zero_pad(X_prev, pad)
    for i in range(m):                               # loop over the batch of training examples
        x_prev_pad = X_prev_pad[i]                   # Select ith training example's padded activation
        for h in range(n_H):                          # loop over vertical axis of the output volume
            for w in range(n_W):                      # loop over horizontal axis of the output volume
                
                # Find the corners of the current "slice" (≈4 lines)
                vert_start = h * stride
                vert_end = vert_start + f
                horiz_start = w * stride
                horiz_end = horiz_start + f
                
                # Use the corners to define the (3D) slice of a_prev_pad (See Hint above the cell). (≈1 line)
                x_slice_step = x_prev_pad[vert_start:vert_end, horiz_start:horiz_end, :]
                for c in range(n_C):                  # loop over channels (= #filters) of the output volume
        
                    # Convolve the (3D) slice with the correct filter W and bias b, to get back one output neuron. (≈1 line)
                    Z[i, h, w, c] = conv_single_step(x_slice_step, W[...,c], b[...,c])
                                        
    
    # Making sure your output shape is correct
    assert(Z.shape == (m, n_H, n_W, n_C))
    
    # Save information in "cache" for the backprop
    cache = (X_prev, W, b, hparameters)
    
    return Z, cache

def pool_forward(X_prev, hparameters, mode = "max"):
    """
    A_prev -- (m, n_H_prev, n_W_prev, n_C_prev)
    hparameters -- python dictionary containing "f" and "stride"
    mode -- ,  ("max" or "average")
    
    Returns:
    A -- shape (m, n_H, n_W, n_C)
    cache -- cache used in the backward pass of the pooling layer, contains the input and hparameters 
    """
    
    # Retrieve dimensions from the input shape
    (m, n_H_prev, n_W_prev, n_C_prev) = X_prev.shape
    
    # Retrieve hyperparameters from "hparameters"
    f = hparameters["f"]
    stride = hparameters["stride"]
    
    # Define the dimensions of the output
    n_H = int(1 + (n_H_prev - f) / stride)
    n_W = int(1 + (n_W_prev - f) / stride)
    n_C = n_C_prev
    
    # Initialize output matrix A
    X = np.zeros((m, n_H, n_W, n_C))              
    
    ### START CODE HERE ###
    for i in range(m):                         # loop over the training examples
        for h in range(n_H):                     # loop on the vertical axis of the output volume
            for w in range(n_W):                 # loop on the horizontal axis of the output volume
               
               # Find the corners of the current "slice" (≈4 lines)
                vert_start = h * stride
                vert_end = vert_start + f
                horiz_start = w * stride
                horiz_end = horiz_start + f
                
                for c in range (n_C):            # loop over the channels of the output volume
                       
                    # Use the corners to define the current slice on the ith training example of A_prev, channel c. (≈1 line)
                    x_prev_slice = X_prev[i, vert_start:vert_end, horiz_start:horiz_end, c]
                    
                    # Compute the pooling operation on the slice. Use an if statment to differentiate the modes. Use np.max/np.mean.
                    if mode == "max":
                        X[i, h, w, c] = np.max(x_prev_slice)
                    else:
                        X[i, h, w, c] = np.mean(x_prev_slice)
    
    ### END CODE HERE ###
    
    # Store the input and hparameters in "cache" for pool_backward()
    cache = (X_prev, hparameters)
    
    # Making sure your output shape is correct
    assert(X.shape == (m, n_H, n_W, n_C))
    
    return X, cache


# =============================================================================
# Convolutional Backward
# =============================================================================

def conv_backward(dZ, cache):
    """
    dZ -- gradient of the cost with respect to the output of the conv layer (Z), numpy array of shape (m, n_H, n_W, n_C)
    cache -- cache of values needed for the conv_backward(), output of conv_forward()
    
    Returns:
    dA_prev -- gradient of the cost with respect to the input of the conv layer (A_prev),
               numpy array of shape (m, n_H_prev, n_W_prev, n_C_prev)
    dW -- gradient of the cost with respect to the weights of the conv layer (W)
          numpy array of shape (f, f, n_C_prev, n_C)
    db -- gradient of the cost with respect to the biases of the conv layer (b)
          numpy array of shape (1, 1, 1, n_C)
    """
    
    ### START CODE HERE ###
    # Retrieve information from "cache"
    (X_prev, W, b, hparameters) = cache
    
    # Retrieve dimensions from A_prev's shape
    (m, n_H_prev, n_W_prev, n_C_prev) = X_prev.shape
    
    # Retrieve dimensions from W's shape
    (f, f, n_C_prev, n_C) = W.shape
    
    # Retrieve information from "hparameters"
    stride = hparameters["stride"]
    pad = hparameters["pad"]
    
    # Retrieve dimensions from dZ's shape
    (m, n_H, n_W, n_C) = dZ.shape
    
    # Initialize dA_prev, dW, db with the correct shapes
    dX_prev = np.zeros((m, n_H_prev, n_W_prev, n_C_prev))                           
    dW = np.zeros((f, f, n_C_prev, n_C))
    db = np.zeros((1, 1, 1, n_C))

    # Pad A_prev and dA_prev
    X_prev_pad = zero_pad(X_prev, pad)
    dX_prev_pad = zero_pad(dX_prev, pad)
    
    for i in range(m):                       # loop over the training examples
        
        # select ith training example from A_prev_pad and dA_prev_pad
        x_prev_pad = X_prev_pad[i]
        dx_prev_pad = dX_prev_pad[i]
        
        for h in range(n_H):                   # loop over vertical axis of the output volume
            for w in range(n_W):               # loop over horizontal axis of the output volume
                
                # Find the corners of the current "slice"
                vert_start = h
                vert_end = vert_start + f
                horiz_start = w
                horiz_end = horiz_start + f
                
                # Use the corners to define the slice from a_prev_pad
                x_slice = x_prev_pad[vert_start:vert_end, horiz_start:horiz_end, :]
                    
                for c in range(n_C):           # loop over the channels of the output volume

                    # Update gradients for the window and the filter's parameters using the code formulas given above
                    dx_prev_pad[vert_start:vert_end, horiz_start:horiz_end, :] += W[:,:,:,c] * dZ[i, h, w, c]
                    dW[:,:,:,c] += x_slice * dZ[i, h, w, c] 
                    db[:,:,:,c] += dZ[i, h, w, c] 
                    
        # Set the ith training example's dA_prev to the unpaded da_prev_pad (Hint: use X[pad:-pad, pad:-pad, :])
        dX_prev[i, :, :, :] = dx_prev_pad[pad:-pad, pad:-pad, :]
    ### END CODE HERE ###
    
    # Making sure your output shape is correct
    assert(dX_prev.shape == (m, n_H_prev, n_W_prev, n_C_prev))
    
    return dX_prev, dW, db

def create_mask_from_window(x):
    """
    Creates a mask from an input matrix x, to identify the max entry of x.
    
    Arguments:
    x -- Array of shape (f, f)
    
    Returns:
    mask -- Array of the same shape as window, contains a True at the position corresponding to the max entry of x.
    """
    
    ### START CODE HERE ### (≈1 line)
    mask = x == np.max(x)
    ### END CODE HERE ###
    
    return mask

def distribute_value(dz, shape):
    """
    Distributes the input value in the matrix of dimension shape
    
    Arguments:
    dz -- input scalar
    shape -- the shape (n_H, n_W) of the output matrix for which we want to distribute the value of dz
    
    Returns:
    a -- Array of size (n_H, n_W) for which we distributed the value of dz
    """
    
    ### START CODE HERE ###
    # Retrieve dimensions from shape (≈1 line)
    (n_H, n_W) = shape
    
    # Compute the value to distribute on the matrix (≈1 line)
    average = dz / (n_H * n_W)
    
    # Create a matrix where every entry is the "average" value (≈1 line)
    a = np.ones(shape) * average
    ### END CODE HERE ###
    
    return a

def pool_backward(dX, cache, mode = "max"):
    """
    Implements the backward pass of the pooling layer
    
    Arguments:
    dA -- gradient of cost with respect to the output of the pooling layer, same shape as A
    cache -- cache output from the forward pass of the pooling layer, contains the layer's input and hparameters 
    mode -- the pooling mode you would like to use, defined as a string ("max" or "average")
    
    Returns:
    dA_prev -- gradient of cost with respect to the input of the pooling layer, same shape as A_prev
    """
    
    ### START CODE HERE ###
    
    # Retrieve information from cache (≈1 line)
    (X_prev, hparameters) = cache
    
    # Retrieve hyperparameters from "hparameters" (≈2 lines)
    stride = hparameters["stride"]
    f = hparameters["f"]
    
    # Retrieve dimensions from A_prev's shape and dA's shape (≈2 lines)
    m, n_H_prev, n_W_prev, n_C_prev = X_prev.shape
    m, n_H, n_W, n_C = dX.shape
    
    # Initialize dA_prev with zeros (≈1 line)
    dX_prev = np.zeros(X_prev.shape)
    
    for i in range(m):                       # loop over the training examples
        # select training example from A_prev (≈1 line)
        x_prev = X_prev[i]
        for h in range(n_H):                   # loop on the vertical axis
            for w in range(n_W):               # loop on the horizontal axis
                
                # Find the corners of the current "slice" (≈4 lines)
                vert_start = h
                vert_end = vert_start + f
                horiz_start = w
                horiz_end = horiz_start + f

                for c in range(n_C):           # loop over the channels (depth)
                    
                    # Compute the backward propagation in both modes.
                    if mode == "max":
                        # Use the corners and "c" to define the current slice from a_prev (≈1 line)
                        x_prev_slice = x_prev[vert_start:vert_end, horiz_start:horiz_end, c]
                        # Create the mask from a_prev_slice (≈1 line)
                        mask = create_mask_from_window(x_prev_slice)
                        # Set dA_prev to be dA_prev + (the mask multiplied by the correct entry of dA) (≈1 line)
                        dX_prev[i, vert_start:vert_end, horiz_start:horiz_end, c] += np.multiply(mask, dX[i, h, w, c])
                        
                    elif mode == "average":
                        # Get the value a from dA (≈1 line)
                        da = dX[i, h, w, c]
                        # Define the shape of the filter as fxf (≈1 line)
                        shape = (f, f)
                        # Distribute it to get the correct slice of dA_prev. i.e. Add the distributed value of da. (≈1 line)
                        dX_prev[i, vert_start:vert_end, horiz_start:horiz_end, c] += distribute_value(da, shape)
                        
    ### END CODE ###
    
    # Making sure your output shape is correct
    assert(dX_prev.shape == X_prev.shape)
    
    return dX_prev

def C_backward_model(dX, caches):
    
    grads={}
    L=len(caches) # number of layers in the network
    convolutional_cache ,pooling_cache, shape = caches[0]
    grads["dA"+str(L+1)]=dX.reshape(shape)
    for l in reversed(range(L)):
        
        convolutional_cache ,pooling_cache, shape = caches[l]
        
        X = pool_backward(grads["dA"+str(l+2)], pooling_cache)
        
        grads["dA" + str(l+1)], grads["dW" + str(l+1)], grads["db" + str(l+1)]  = conv_backward(X,convolutional_cache)
   
    return grads
    
def C_forward_model(X, Cparameters, hparameters):
        
    caches=[]
    
    L = len(Cparameters) // 2 # number of layers in the network
    
    for j in range(0,L):
        X, convolutional_cache = conv_forward(X,Cparameters['W' + str(j+1)],Cparameters['b' + str(j+1)],hparameters[j-1][0])
        X, pooling_cache = pool_forward(X,hparameters[j][1])
        caches.append([convolutional_cache,pooling_cache,X.shape])
    
    X = X.reshape((X.shape[0] , np.prod(X.shape[1:])))
    
    return X, caches