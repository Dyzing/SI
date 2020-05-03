			*****************************************************************************************************************************************
			******************************************************************DOCUMENTATION**********************************************************
			*****************************************************************************************************************************************
 
Introduction : 
 
	Ce projet a été réalisé en C sur la base d'OpenGL. Le sujet du projet est un animatronique, ici un colibri. Il a été réalise en autonomie.
L'utilisateur peut contrôler le sujet ainsi que la caméra indépendamment de l'autre. Une réplique du sujet s'anime de manière autonome et aléatoirement au second plan.

			*****************************************************************************************************************************************
Présentation de l'environnement :

	L'environnement du sujet est un jardin suspendu.
Il est entouré d'un enclos.
Surplanant le vide, il reste toutefois illuminé par des astres (soleil & lune) et surplombé de quelques nuages animés dans l'espace dont leur forme ressemble particulièrement à celle du jeu vidéo "Minecraft" (voir image dans le dossier : nuage-minecraft.png) dans un ciel bleu clair pendant le jour et bleu sombre pendant la nuit. 
Le sol est de couleur verte afin d'illustrer l'herbe.
Un rocher décore l'île.
Une cascade d'eau (transparente) vient se jeter dans le vide.
Une fleur avec ses pétales roses transparentes afin de pouvoir observer son pollen jaune prend place sur la scène. L'oiseau peut interagir avec cette fleur ce qui sera expliqué plus tard dans la documentation.
Un lampadaire se situe au centre de la scène au second plan. Il peut s'allumer ou s'éteindre. Cela sera expliqué plus tard dans la documentation.
Ensuite, un autre colibri anime la scène en bougeant de haut en bas et en tournant sur lui-même. De plus, il bouge tous ses membres (tête, queue, aile) afin de montrer toutes les fonctions que le sujet peut faire-
Enfin, la scène est baignée dans une lumière ambiante, l'astre du soleil émet une lumière directionnelle vers la scène et le lampadaire émet une lumière positionnelle que l'on peut allumer et éteindre à sa guise.

			*****************************************************************************************************************************************

Capacité & fonctions du sujet :

	Le colibri peut se mouvoir selon les désirs de l'utilisateur.
En effet, ses ailes, sa tête, sa queue ainsi que son corps entier peuvent bouger. Seulement les ailes de l'oiseau bougent de manières autonomes de haut en bas (tel un oiseau commun). 
Avec certaines touches du clavier, le sujet peut bouger indépendamment des autres certaines parties de son corps.
Ainsi, l'oiseau peut bouger sa tête de haut en bas, sa queue de haut en bas, orienter son corps de haut en bas et son corps entier dans l'espace en choisissant la direction de son mouvement en fonction de l'angle horizontal où duquel il est orienté mais seulement en deux dimensions. C'est-à-dire qu'il ne peut se diriger que selon l'axe X/Z.
Donc l'utilisateur peut choisir l'angle de l'oiseau et s'il veut le faire avancer ou reculer.

	Enfin, le colibri peut avec une certaine touche du clavier, se diriger vers la fleur et y venir se substenter de son pollen.
Avec une autre touche, il peut sortir de la fleur et arrêter de prélever le pollen.


			*****************************************************************************************************************************************

Touches du clavier :

	Voici les touches du clavier ayant des fonctions particulières. Il faut différencier les touches MAJ/MIN qui correspondent bien effectivement à la touche en majuscule et en minuscule respectivement. Lorsque ni MAJ, ni MIN sont précisés, cela veut dire que cela importe peu et qu'elles ont le même effet.

Commandes concernant le sujet :

- Z : avancer l'oiseau
- Q : tourner l'angle de l'oiseau vers la gauche
- S : reculer l'oiseau
- D : tourner l'angle de l'oiseau vers la droite

- A (maintenu) : monter l'inclinaison de l'oiseau vers le haut
- E (maintenu) : descendre l'inclinaison de l'oiseau vers le bas

- MAJ + R (maintenu) : monter l'inclinaison de la tête du sujet vers le haut
- MIN + R (maintenu) : descendre l'inclinaison de la tête du sujet vers le bas

- MIN + T (maintenu) : monter l'inclinaison de la queue du sujet vers le haut
- MAJ + T (maintenu) : descendre l'inclinaison de la queue du sujet vers le bas

- MIN + C (maintenu) : faire prélever du pollen à l'oiseau
- MAJ + C (maintenu) : Arrêter de faire prélever du pollen à l'oiseau


Commandes concernant la caméra : 

- O (maintenu) : avancer la caméra
- K (maintenu) : tourner l'angle de la caméra vers la gauche
- L (maintenu) : reculer la caméra
- M (maintenu) : tourner l'angle de la caméra vers la droite

- I (maintenu) : descendre la caméra
- P (maintenu) : monter la caméra

- Touche directionnelle du haut (maintenu) : monter l'inclinaison de la caméra vers le haut
- Touche directionnelle de gauche (maintenu) : tourner l'inclinaison de la caméra vers la gauche
- Touche directionnelle du bas (maintenu) : descendre l'inclinaison de la caméra vers le bas
- Touche directionnelle de droite (maintenu) : tourner l'inclinaison de la caméra vers la droite

- Espace : repositionne la caméra à son emplacement et à son orientation initiale


Commandes concernant l'environnement :

- B : alterne le ciel et l'astre entre le jour et la nuit
- N : allume ou éteint le lampadaire

Commande globale :

- Échap : quitte et ferme la fenêtre de l'application


			*****************************************************************************************************************************************
			
Explication globale du code :

	En résumé, j'ai écrit mon code principal dans le main.c, j'ai créé deux oiseaux, l'un qui est le sujet et l'autre la réplique. J'y ai aussi créé chaque élément de l'environnement.
Dans action.c se trouve toutes les interactions avec les touches du clavier (écrites dans touche.h).
La caméra est paramétrée dans VM_init.c.


			*****************************************************************************************************************************************
			
Compilation : 

	Afin de compiler le code, selon les machines il faut ajouter l'option -no-pie à la ligne de compilation. 
Voici ainsi les deux lignes de code selon le besoin à taper dans le terminal de commande :

	_ gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test
	_ gcc main.c actions.c axes.o init.c lumiere.o switch_blend.o  switch_light.o VM_init.c -lm -lGL -lGLU -no-pie -lglut -o test
	
Enfin pour tester le code, il suffit de taper dans le terminal de commande la ligne suivante :

	_ ./test


Ou bien il faut tout simplement taper dans la ligne de commande du terminal : 

	_ make
	
et cela appellera la makefile du dossier et compilera le projet.
Si la commande ne fonctionne pas, il faut enlever alors l'option -no-pie de la ligne de commande du makefile (dépendant des ordinateurs) et ressayer.


			*****************************************************************************************************************************************
						
																				
Guillaume TREM, le 27/03/2020.
	




