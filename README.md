# BigMat
## Gérer des matrices creuses de grandes tailles

### La librairie
Cette librairie à majoritairement été écrite en utilisant des templates, afin de permetre la gestion efficace en mémoire de plusieurs types de matrices.
Une matrice de _short_ utilisera moins de mémoire qu'une matrice de type _long_

### Opérations arithmétiques sur les matrices
Les opérations de base ont été implémentés sous la forme de surcharge d'opérateurs.
Cela signifie que vous pouvez utiliser les opérateurs +=, -= *= et /= sur les matrices.
Pour des raisons d'espace mémoire, les opérateurs +, -, * et / n'ont pas été implémentés car ils nécessitent de cloner la matrice.
Ces opérations sont implémentés dans le header **MathMatrix**.


### Formatage des données
La librairie peut lire des fichiers texte contenant les matrices grâce aux fonctions statiques de la classe **MatrixReader**
Le format d'entrée est le suivant (pour une matrice de short, par exemple):

```
0 0 2
0 1 1
0 3 5
2 2 4
5 1 6
5 3 4
5 5 6
```

Ce fichier produira une matrice de taille 5x5

La classe **MatrixExport** permet d'exporter les matrices sous ce même format.

### Tests
Pour lancer les tests, utilisez l'outil make: `make exectest`
