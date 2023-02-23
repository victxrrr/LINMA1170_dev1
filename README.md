<h1 align="center">
  <br>
  LINMA1170 – Analyse Numérique
  <br>
</h1>

<h4 align="center">Devoir 1 : Résolution de systèmes linéaires</h4>

<p align="center">
  <a href="#usage">Usage</a> •
  <a href="#auteurs">Auteurs</a>
</p>


## Usage

Le répertoire propose les fonctionnalités ci-dessous.

```bash
# Lance le script de tests vérifiant l'exactitude des fonctions définies dans matrix.h
$ make test_mat

# Lance le script de tests vérifiant l'exactitude des fonctions définies dans lu.h
$ make test_lu

# Lance le script de mesurant la complexité de l'ensemble des algorithmes étudiés
# Les mesures sont écrites dans <data.txt>
$ make complex

# Affiche graphiquement les données obtenues
$ make plot

# Nettoye le répertoire
$ make clean

```

> **Note**
> L'exécution de `make test_lu` et `make complex` peut prendre un certain temps.

## Auteur

Ce répertoire a été entièrement implémenté par Victor Lepère.

---

> GitHub [Répertoire](https://github.com/victxrrr/LINMA1170_devoir1) &nbsp;&middot;&nbsp;
> [Victor Lepère](mailto:victor.lepere@student.uclouvain.be) &nbsp;&middot;&nbsp;
> GitHub [@victxrrr](https://github.com/victxrrr)