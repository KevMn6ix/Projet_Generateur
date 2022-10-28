cmake_minimum_required(VERSION 3.21)
project(Projet_Generateur C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_Generateur main.c n-tree.c n-tree.h tree_nom.c tree_nom.h tree_adject.c tree_adject.h tree_adv.c tree_adv.h)
