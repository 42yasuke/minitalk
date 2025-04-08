# 🧑‍💻 minitalk

**minitalk** est un projet qui consiste à créer un serveur et un client en C, capables de communiquer entre eux en envoyant des signaux Unix. Ce projet permet de mieux comprendre l'utilisation des signaux et leur gestion dans un environnement multitâche.

## 🛠️ Objectif

L'objectif du projet est d'implémenter une communication entre deux programmes (serveur et client) en utilisant les signaux Unix. Le serveur doit recevoir un message sous forme binaire (en utilisant des signaux) et le client doit envoyer des signaux au serveur pour lui transmettre ce message.

## 🧩 Fonctionnalités Implémentées

- Le client envoie un message au serveur en utilisant des signaux `SIGUSR1` et `SIGUSR2`.
- Le serveur reçoit les signaux, les interprète et reconstruit le message.
- Une fois le message entièrement reçu, le serveur affiche le message à l'écran.
- La communication entre le client et le serveur fonctionne de manière asynchrone.
- La gestion des erreurs et des signaux est propre et optimisée.

## 🧪 Compilation et Utilisation

### Compilation

Le projet utilise un `Makefile` pour faciliter la compilation.

```bash
make
```

Pour nettoyer les fichiers objets :

```bash
make clean
```

Pour supprimer tous les fichiers compilés (objets + exécutable) :

```bash
make fclean
```

Pour recompiler le projet :

```bash
make re
```

### 📄 Utilisation

Voici un exemple simple d'utilisation de minitalk :

1. Lance le serveur dans un terminal :
 ```bash
./server
```
2. Dans un autre terminal, envoie un message avec le client :
 ```bash
./client 12345 "Hello, minitalk!"
```
