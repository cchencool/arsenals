ó
kXc           @   s)   d  Z  d d l Z d d d     YZ d S(   s4   
Created on Sun Oct 30 11:39:47 2016

@author: Chen
iÿÿÿÿNt   Toolc           B   sz   e  Z e j d   Z e j d  Z e j d  Z e j d  Z e j d  Z e j d  Z	 e j d  Z
 d   Z RS(   s   <img.*?>| {1,7}| s   <a.*?>|</a>s   <tr>|<div>|</div>|</p>s   <td>s   <br><br>|<br>s   <.*?>s   
+c         C   s²   t  j |  j d |  } t  j |  j d |  } t  j |  j d |  } t  j |  j d |  } t  j |  j d |  } t  j |  j d |  } t  j |  j d |  } | j	   S(   Nt    s   
s   	(
   t   ret   subt	   removeImgt
   removeAddrt   replaceLinet	   replaceTDt	   replaceBRt   removeExtraTagt   removeNoneLinet   strip(   t   selft   x(    (    s   Tool.pyt   replace   s    (   t   __name__t
   __module__R   t   compileR   R   R   R   R   R	   R
   R   (    (    (    s   Tool.pyR       s   (    (   t   __doc__R   R    (    (    (    s   Tool.pyt   <module>   s   