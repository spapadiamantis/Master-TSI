# -*- coding: utf-8 -*-
"""
TP2 06/11

Python Sotirios Papadiamantis
"""

import numpy as np
from skimage import data, color
import matplotlib.pyplot as plt


def Coefficient(T, k):
    """
   :param T: Uni-dimensional table
   :param k: k variable
   :return: Coefficient for uni-dimensional Fourrier transfrom
   """

    coeff = 0
    # Calculate TF coefficient based on k
    for i in range(0, T.size):
        coeff += T[i] * np.exp(-2j * np.pi * ((k * i) / T.size))

    return coeff


def TF(T):
    """
   Calculate the Fourier Transform of T table
   :param T: array of numbers
   :return: Fourier Transform
   """

    # Allocating Fourier Table
    F = np.zeros(T.size, dtype=complex)

    # Calculate TF coefficient for every element
    for i in range(0, T.size):
        F[i] = Coefficient(T, i)

    return F


def CoefficientInv(T, k):
    """
   Claculate the Inverse Fourrier Transform Coefficient for an element
   :param T: array of numbers
   :param k: number of element
   :return:
   """
    coeff = 0
    for i in range(0, T.size):
        coeff += T[i] * (np.exp(2j * np.pi * ((k * i) / T.size)))
    coeff = coeff / T.size

    return coeff


def TFInv(T):
    FInv = np.zeros(T.size, dtype=complex)
    for i in range(0, T.size):
        FInv[i] = CoefficientInv(T, i)
    return FInv


def Coefficient2D(T, k1, k2):
    coeff = 0
    N, M = T.shape
    for i in range(0, N):
        for z in range(0, M):
            coeff += T[i][z] * (np.exp(-2j * np.pi * ((k1 * i) / N) + (k2 * z) / M))
    return coeff


def TF2(I):
    FI = np.zeros(I.shape, dtype=complex)
    N, M = I.shape
    for i in range(0, N):
        for j in range(0, M):
            FI[i][j] = Coefficient2D(I, i, j)
    return FI


def Coefficient2DInv(T, k1, k2):
    coeff = 0
    for i in range(0, T.size):
        for z in range(0, T[0].size):
            coeff += T[i][z] * (np.exp(2j * np.pi * ((k1 * i) / T.size) + (k2 * z) / T[0].size))
    coeff = coeff / T.size
    return coeff


def TFInv2(I):
    FI = np.zeros(I.shape, dtype=complex)
    for i in range(0, I.size):
        for j in range(0, I[0].size):
            FI[i][j] = Coefficient2DInv(I, i, j)
    return FI


def MonFiltre(I):
    """
   Filter function for Image using FFT
   :param I: input Image
   :return:
   """

    TFI = np.fft.fft2(I)
    keep_fraction = 0.005

    im_fft2 = TFI.copy()

    r, c = im_fft2.shape

    im_fft2[int(r * keep_fraction):int(r * (1 - keep_fraction))] = 0

    im_fft2[:, int(c * keep_fraction):int(c * (1 - keep_fraction))] = 0

    im_new = np.fft.ifft2(im_fft2).real

    return im_new


def ImageDistance(I1, I2):
    """
   Calculate Distance of two same shaped Images
   :param I1: array of Image
   :param I2: array of Image
   :return:   sum of distances between each pixel
   """

    dist = 0
    N, M = I1.shape
    for i in range(0, N):
        for j in range(0, M):
            dist += np.abs(I1[i][j] - I2[i][j])

    return dist


if __name__ == "__main__":
    I = color.rgb2gray(data.astronaut())
    plt.imshow(I)
    plt.show()
    print("Image shape is", I.shape)

    #   print(Coefficient(I[0],5))
    #   print(TF(I[0]))
    #   print(TFInv(TF(I[0])))
    #   L = I[50:100]
    #   plt.plot(TF2(L).real)
    #   plt.show()

    Bruit = np.random.randn(len(I), I[0].size)
    Bruit = (Bruit - Bruit.min()) * 0.2
    IBruit = Bruit + I
    plt.imshow(IBruit)
    plt.show()

    IFiltre = MonFiltre(IBruit)
    plt.imshow(IFiltre)
    plt.title('Reconstructed Image')
    plt.show()

    print(np.sum(np.abs(I - np.zeros(I.shape))))
    print(ImageDistance(I, IFiltre))
    print(ImageDistance(I, IBruit))
