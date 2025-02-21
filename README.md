# Travail pratique 3 : Le jeu *Circles*

## Description

#### INF3135 - AUTOMNE 2024 - UQAM
* Jeu Inspiré de Super Hexagon

Ce projet pour le cours **INF3135** est un jeu vidéo inspiré de *Super Hexagon* de Terry Cavanagh. Le joueur contrôle une flèche rouge qui tourne autour d’un centre, tout en évitant des obstacles qui apparaissent de manière aléatoire. L’objectif principal est de survivre le plus longtemps possible en esquivant ces obstacles.

Le jeu propose trois niveaux de difficulté : **Easy**, **Normal**, et **Hard**, chacun augmentant la vitesse des obstacles. Avec une esthétique minimaliste et un gameplay addictif, ce projet met en valeur des concepts clés en programmation tels que la gestion des événements, les animations graphiques, et l’intégration audio pour une expérience immersive.

## Auteurs

- Olivier Généreux-Vincent
- Kaikou Loic Degni

## Dépendances

Avant de pouvoir exécuter le projet, il est nécessaire d'installer plusieurs dépendances logicielles et bibliothèques. Ces dépendances sont essentielles au bon fonctionnement du jeu.

Pour un MacOS avec puce M2, il est essentiel de telecharger les dependances cite plus bas avec homebrew et d'utiliser les options de compilation et d'editions menant aux dossier homebrew. Dependament de la configuration de votre votre Mac et de la version des librairies telecharge, il faudrait peut etre modifier les chemins vers les differentes librairies.

Pour ce qui est d'Ubuntu les options de compilation pkg-config permettront de compiler l'executable du jeu. 

##### Logiciels

- **Compilateur GCC**  
  Le projet nécessite un compilateur C pour compiler le code source. Vous pouvez utiliser GCC ou Clang. Ces compilateurs sont généralement installés par défaut sur les systèmes Unix, Ubuntu et macOS avec Xcode.  
  [Site officiel de GCC](https://gcc.gnu.org/)


#### Bibliothèques

- **SDL2 (Simple DirectMedia Layer 2)**  
  SDL2 est utilisé pour la gestion des graphiques, des entrées utilisateur et de l'audio.  
  [Site officiel de SDL2](https://www.libsdl.org/)

- **SDL2_mixer**  
  Cette bibliothèque permet de gérer les effets sonores et la musique dans le jeu. Elle s’appuie sur SDL2 pour fournir des fonctionnalités audio avancées.  
  [Site officiel de SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/)

- **SDL2_image**  
  SDL2_image est utilisé pour charger et afficher des images dans différents formats (PNG, JPEG, etc.).  
  [Site officiel de SDL2_image](https://www.libsdl.org/projects/SDL_image/)

- **SDL2_gfx**  
  Cette bibliothèque est utilisée pour dessiner des formes géométriques, des lignes, et gérer des effets graphiques simples.  
  [Site officiel de SDL2_gfx](https://www.ferzkopp.net/Software/SDL_gfx/)

## Fonctionnement

* Pour compiler, allez dans le dossier /src.  Par la suite, faire la commande 'make'.
* Pour partir le jeux, faire la commande './circle'
* Les flèches servent à naviguer dans le menu et la touche 'Enter' permet de faire les choix.

#### Objectif du jeu
Le but du jeu est de survivre le plus longtemps possible en évitant les obstacles.

#### Navigation dans le menu
* Utilisez les flèches pour naviguer dans le menu.
* La touche `Enter` permet de faire un choix.

#### Menu principal
Le jeu débute sur la page du menu. Vous pouvez choisir parmi trois niveaux de difficulté.
![Menu principal](./assets/screen_menu.png)

#### Choix de la difficulté
Après avoir sélectionné "Difficulty", vous choisissez le niveau de difficulté.
![Sélection de la difficulté](./assets/screen_difficulty.png)

#### Pendant le jeu
Le jeu commence après avoir cliqué sur "Play". Le chronomètre est affiché en haut à droite de l'écran.
![Jeu en cours](./assets/screen_play.png)

#### Déplacement du joueur
Pour déplacer le joueur, appuyez sur les flèches `GAUCHE` et `DROITE`.

#### Fin du jeu
Si vous touchez un obstacle, l'écran de fin apparaît. Appuyez sur la touche `Enter` pour revenir au menu principal.
![Écran de fin](./assets/screen_end.png)


## Plateformes supportées

* MacOS M2
* Ubuntu

## Références

N.A

## Division des tâches

Donnez ici une liste des tâches de chacun des membres de l'équipe. Utilisez la
syntaxe suivante (les crochets vides indiquent que la tâche n'est pas
complétée, les crochets avec un `X` indique que la tâche est complétée):

* [X] Gestion du menu (Olivier)
* [X] Affichage de la scène (Olivier, Loic)
* [X] Affichage du chronomètre (Loic)
* [X] Animation des murs (Loic, Olivier)
* [X] Animation du joueur (Olivier)
* [X] Détection des collisions (Olivier, Loic)
* [X] Affichage d'une partie terminée (Loic)
* [X] Gestion de la musique principale (Olivier)
* [ ] Gestion des sons lorsqu'on navigue dans le menu
* [ ] Gestion de la musique de fin de partie

## État du projet

Le programme marche sans bogue du début à la fin.  Plusieurs parties peuvent être effectuer une à la suite de l'autre.
