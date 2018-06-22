# K-NN_Demo

K-NN Demo using Data Set: UCI Letter Recognition

[![UCI ML Repo](http://archive.ics.uci.edu/ml/assets/logo.gif)](http://archive.ics.uci.edu/ml/datasets/Letter+Recognition)

## Data Set Information:

The objective is to identify each of a large number of black-and-white rectangular pixel displays as one of the 26 capital letters in the English alphabet. The character images were based on 20 different fonts and each letter within these 20 fonts was randomly distorted to produce a file of 20,000 unique stimuli. Each stimulus was converted into 16 primitive numerical attributes (statistical moments and edge counts) which were then scaled to fit into a range of integer values from 0 through 15. We typically train on the first 16000 items and then use the resulting model to predict the letter category for the remaining 4000. See the article cited above for more details.

## Attribute Information:

1.	lettr	capital letter	(26 values from A to Z) 
2.	x-box	horizontal position of box	(integer) 
3.	y-box	vertical position of box	(integer) 
4.	width	width of box	(integer) 
5.	high height of box	(integer) 
6.	onpix	total # on pixels	(integer) 
7.	x-bar	mean x of on pixels in box	(integer) 
8.	y-bar	mean y of on pixels in box	(integer) 
9.	x2bar	mean x variance	(integer) 
10.	y2bar	mean y variance	(integer) 
11.	xybar	mean x y correlation	(integer) 
12.	x2ybr	mean of x * x * y	(integer) 
13.	xy2br	mean of x * y * y	(integer) 
14.	x-ege	mean edge count left to right	(integer) 
15.	xegvy	correlation of x-ege with y	(integer) 
16.	y-ege	mean edge count bottom to top	(integer) 
17.	yegvx	correlation of y-ege with x	(integer)

## Data Input

```
.
├── test100.txt
└── train19900.txt
```

- test100 contains 100 samples, acting as testing set.
- train19900 contains 19900 samples, acting as training set.

## Compile and Run

```
$> gcc K-NN_Demo.c -o knn
$> ./knn
```

it will then prompt you to input `K` in K-NN algorithm: here I'm using `1`

```
               ************************************************************************************************
               *                           K-NN Demo using Data Set: UCI Letter Recognition                   *
               *                                       - [Yang (Simon) Guo] -                                 *
               ************************************************************************************************

rows of training data set: 19900
rows of test data set: 100
input K in K-nearest-neighbour algorithm: 1
```

## Results

```
-------------------TEST RESULT SUMMARY-------------------
right prediction: 97
wrong prediction: 3
accuracy: 97.000% [0.970000]
```

## LICENSE

Copyright (c) 2018 Yang (Simon) Guo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
