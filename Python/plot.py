#! /usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = "chen"


import matplotlib.pyplot as plt
from numpy.random import randn


def main():
    fig = plt.figure()
    ax1=fig.add_subplot(2,2,1)
    ax2=fig.add_subplot(2,2,2)
    ax3=fig.add_subplot(2,2,3)
    plt.plot(randn(50).cumsum(), 'k--')
    plt.show()

if __name__ == '__main__':
    main()