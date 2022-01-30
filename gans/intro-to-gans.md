# What is a GAN (Generative Adversarial Network)

A Gan is a type of Network used to generate 2d images. In laymans terms, we give the network some random data, and try to detect if it is real. If we can trick our code into thinking its real we are good to go. Thats a very basic explaination. Lets Talk more about those magical steps.

# The Magic of GANS
1. The Generator
We can use the generator to create new images. Generative models learn the intrinsic distribution function of the input data, p(x) p(x,y) if there are multiple targets or parameters we want to try.

## Some Cool features of Gans.
1. They generate the sharpest images ;)
2. They are easy to train as no statisitical inference is required. and the only loop would be to obtain the new gradients.


# Understanding wtf a GAN is
There are two major models we are building in a GAN.
1. The Generator.
I mentioned it earler but the generator is responsible for creating new data with similarity to the expected data. 
2. The discriminator
The second model is called the discriminator. This models goal is to recognize if the generated artwork is real. 

The feedback loop looks something like this
```

Generator -> Discriminator --- Is data correct? 
^				^					|
|				|					|
|< ------------Fine tune<------------
```

Forgive the scuffed art but hopefully you get the general idea.

# Mathematically Modeling a GAN
A neural network G(z, theta1) is used to model the generator mentioned above.
Its role is mapping the input noise variables z to the desired data space x.

Then we will have a second neural network D(x, theta2) that models the discriminator and outputs the probablity that the data came from teh real dataset.

As a result, the discriminator is trained to correctly classify the input data as either real or fake this means its weights are updated as to maximize the probablity that any real data input data x is classifed as belonging to the original dataset, while minimizing the probablity that any fake image is classifed as belonging to a the real dataset. Its a loss/error function.

We then train the generator to fool the discriminator by generating data as realistic as possible, which means the generators weights are optimized to maximize the probablity that any fake image is classifed as belonging to the real dataset. 

# Steps to training a GAN
1. Sample a noise set and a real-data set, each with some declared size m.
2. Train the Discriminator on this data.
3. Sample a different noise subset with size m.
4. Train the generator on this data
5. Repeat the process from step 1.
