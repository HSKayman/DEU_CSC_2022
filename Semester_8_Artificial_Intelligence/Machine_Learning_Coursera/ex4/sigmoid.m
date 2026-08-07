% Sigmoid practice program.
% Coursera ML/DL assignment code (Machine Learning Coursera).
% Sigmoid practice program.
% Coursera ML/DL assignment code (Machine Learning Coursera).
function g = sigmoid(z)
%SIGMOID Compute sigmoid functoon
%   J = SIGMOID(z) computes the sigmoid of z.

g = 1.0 ./ (1.0 + exp(-z));
end
