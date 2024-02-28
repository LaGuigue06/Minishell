Guide MINISHELL

Plan:	I - Qu'est ce que Minishell ?
			1.Le sujet
			2.Appréhender le projet
			3.fonction autoriser
		II - Avant le Paring
			1.Les variables d'environements
			2.Le PATH
			3.Le prompt
		III - Le Parsing
			1.Potentiel Structure.
			2.Les separation
			3.Les pipes
			4.Commande et argument
			5.Les protection
			6.Les redirection <,>, >>
			7.Les variables d'environement
		IV - L'Excution
			1.Les redirection
			2.Env, export, unset
			3.Exit et $?
			4.Liens pipes/signaux/processus

I - Qu'est ce que Minishell ?
	1.le sujet

Reproduire un minishell, definition d'un shell :

Un shell Unix est un interpréteur de commandes destiné aux systèmes d'exploitation Unix et de type Unix qui permet d'accéder aux fonctionnalités internes du système d'exploitation. Il se présente sous la forme d'une interface en ligne de commande accessible depuis la console ou un terminal. L'utilisateur lance des commandes sous forme d'une entrée texte exécutée ensuite par le shell. Dans les différents systèmes d'exploitation Microsoft Windows, le programme analogue est command.com, ou cmd.exe.

Les systèmes d'exploitation de type Unix disposent le plus souvent d'un shell. À l'origine, l'interpréteur de commandes par défaut était sh, qui donna naissance à de nombreuses variantes, dont csh, étendu en tcsh, ou ksh, ou encore rc... Mais aujourd'hui bash, s'inspirant de sh, ksh, et csh, est le shell le plus répandu, bien qu'il existe d'autres interpréteurs de commandes, comme zsh, ou ash. 

	2.Appréhender le projet

Rien de mieux que de lire le man de bash !
http://manpagesfr.free.fr/man/man1/bash.1.html.

	3.fonction autoriser

Liste de toutes les fonction autoriser par le sujet.
ATTENTION : Beaucoup de fonction autoriser par le sujet ne seront propablement utiliser pour la realisation du projet !!!

Toute les fonction autorise :
	-readline:	syntaxe: char   *readline(const char *prompt)
				Cette fonction va lire une ligne dans le promp et va la retourner, si la ligne est vide NULL sera retourner.
				La ligne retourne est une chaine de character malloc il faut donc la free.
	
	-rl_clear_history:	syntaxe: void rl_clear_history(void)
						Efface la liste de l'historique en supprimant toutes les entrées, de la même manière que la fonction clear_history() de la bibliothèque History.
  						que la fonction clear_history() de la bibliothèque History. Cette fonction diffère de
						de clear_history car elle libère les données privées que Readline enregistre dans la liste d'historique.
						Tout ce que j'ai put trouver sur cette fonction...
	
	-rl_on_new_line:	syntaxe: int rl_on_new_line(void)
						Indiquer aux fonctions de mise à jour que nous sommes passés à une nouvelle ligne (vide), généralement après avoir mis une nouvelle ligne.
						Pas tout compris ...
	
	-rl_replace_line:	syntaxe: void rl_replace_line(const char *text, int clear_undo)
						Remplacer le contenu de rl_line_buffer par du texte. Le point et la marque sont préservés, si possible. Si clear_undo est différent de zéro,
						la liste d'annulation associée à la ligne courante est effacée.
	
	-rl_redisplay:	syntaxe: int rl_redisplay(void)
					Modifier ce qui est affiché à l'écran(prompt ???) pour refléter le contenu actuel de rl_line_buffer.

	-add_history:	syntaxe: void add_history(const char *string)
					Place la chaîne de caractères à la fin de la liste historique. Le champ de données associé (le cas échéant) est mis à NULL.
					Pas compris ...
	
	-access:	syntaxe: int access(const char *path, int mode)
				Vérifie si le processus appelant peut accéder au fichier pathname, retourne 0 si il reussit et -1 si il echoue.
				le mode indique la (les) vérification(s) d'accessibilité à effectuer et est soit la valeur F_OK, soit un masque constitué par un OU binaire « | » entre les valeurs R_OK, W_OK et X_OK. F_OK R_OK, W_OK et X_OK servent à tester respectivement,
				si le fichier existe, la lecture, l'écriture et l'exécution du fichier.
	
	-fork:		syntaxe: pid_t fork(void)
				Crée un nouveau processus en dupliquant le processus appelant. Le nouveau processus, que l'on appelle processus fils, est la copie exacte du processus appelant, que l'on appelle processus père ou parent, avec les exceptions suivantes : 
					    .Le fils a son propre identifiant de processus (PID). Ce PID est unique et ne correspond à aucun autre identifiant de groupe de processus existant (setpgid(2)). 
    					.Le PPID (Parent Process ID) du fils est identique au PID du parent. 
    					.Le fils n'hérite pas des verrouillages mémoire de son parent (mlock(2), mlockall(2)). 
    					.Les statistiques d'utilisation des ressources de processus (getrusage(2)) et les compteurs de temps CPU (times(2)) sont réinitialisés dans le fils. 
    					.L'ensemble des signaux en attente dans le fils est initialement vide (sigpending(2)). 
    					.Le fils n'hérite pas des ajustements de sémaphore de son parent (semop(2)). 
    					.Le fils n'hérite pas des verrous d'enregistrement de son parent (fcntl(2)). 
    					.Le fils n'hérite pas des temporisations de son parent (setitimer(2), alarm(2), timer_create(3)). 
    					.Le fils n'hérite pas des opérations d'E/S asynchrones en cours de son parent (aio_read(3), aio_write(3)).
				return value: si la focntion retorune -1 alors elle a echouer sinon 0 correspond au fil et autre valeur correspond au pere !
				ex :	pid_t	pid;
						pid = fork();
						if (pid == -1)
							fail;
						if (pid == 0)
							processus du fils;
						processus du pere;
	
	-wait:	syntaxe: pid_t wait(int *status)
			Tous ces appels système sont utilisés pour attendre le changement d'état du fils d'un processus appelant, et pour obtenir des informations sur le fils dont l'état a changé.
			Un changement d'état peut être : le fils est terminé ; le fils a été interrompu par un signal ; ou le fils a été relancé par un signal.
			Dans le cas de la fin d'un processus, la réalisation d'un wait() permet au système de libérer les ressources associées au fils ; si un wait() n'est pas effectué, le fils qui s'est terminé reste dans l'état de « zombie ».
			Si le fils a déjà changé d'état, ces appels reviennent immédiatement. Autrement, ils bloquent jusqu'à ce que soit un fils change d'état, soit un gestionnaire de signaux interrompe l'appel.
			En cas de réussite, le PID du fils qui s'est terminé est renvoyé, en cas d'échec -1 est renvoyé. 

	-waitpid:	syntaxe: pid_t waitpid(pid_t pid, int *status, int option).
				Utiliter similaire a la fonction wait(), mais on peut mettre en argument le pid du processus a attendre.
				L'appel système waitpid() suspend l'exécution du processus appelant jusqu'à ce que le fils spécifié par son pid ait changé d'état. Par défaut, waitpid() n'attend que les fils terminés, mais ce comportement est modifiable avec l'argument options comme décrit plus loin.
				La valeur de pid peut être l'une des suivantes :
																. Inferieur a -1: Attendre la fin de n'importe lequel des processus fils dont le GID du processus est égal à la valeur absolue de pid.
																. -1: Attendre n'importe lequel des processus fils. 
																. 0: Attendre n'importe lequel des processus fils dont le GID du processus est égal à celui du processus appelant. 
																. Superieur a 0: Attendre n'importe lequel des processus fils dont le PID est égal à pid.
				Options specifique a Linux :
											.WIFEXITED(status): Renvoie vrai si le fils s'est terminé normalement, c'est-à-dire par un appel à exit(3) ou _exit(2), ou bien par un retour de main().
											.WEXITSTATUS(status): Renvoie le code de sortie du fils. Ce code est constitué par les 8 bits de poids faibles de l'argument status que le fils a fourni à exit(3) ou à _exit(2) ou l'argument d'une commande de retour dans main(). Cette macro ne peut être évaluée que si WIFEXITED a renvoyé vrai.
											.WIFSIGNALED(status): Renvoie vrai si le fils s'est terminé à cause d'un signal. 
											.WTERMSIG(status): Renvoie le numéro du signal qui a causé la fin du fils. Cette macro ne peut être évaluée que si WIFSIGNALED a renvoyé vrai.
											.WCOREDUMP(status): Renvoie vrai si le fils a créé un fichier core. Cette macro ne peut être évaluée que si WIFSIGNALED a renvoyé vrai. Cette macro n'est pas décrite par POSIX.1-2001 et n'est pas disponible sur certaines implémentations (par exemple AIX, SunOS). N'utilisez ceci qu'encadré par #ifdef WCOREDUMP ... #endif.
											.WIFSTOPPED(status): Renvoie vrai si le fils a été arrêté par la délivrance d'un signal. Cette macro n'a de sens que si l'on a effectué l'appel avec l'option WUNTRACED ou lorsque l'appel est en cours de suivi (voir ptrace(2)). 
											.WSTOPSIG(status): Renvoie le numéro du signal qui a causé l'arrêt du fils. Cette macro ne peut être évaluée que si WIFSTOPPED renvoie vrai.
											.WIFCONTINUED(status)(depuis Linux 2.6.10): Renvoie vrai si le processus fils a été relancé par la délivrance du signal SIGCONT.

	-wait3 et wait4:	syntaxe: pid_t wait3(int *status, int option, struct rusage *rusage)
								 pid_t wait4(pid_t pid, int *status, int option, struct rusage *rusage)
						Les appels système wait3() et wait4()  sont  similaires  à  waitpid(2), mais  retournent  également  des  informations  sur  l’utilisation  des ressources par le fils dans la structure pointée par rusage.

	-signal:	syntaxe: sighandler_t signal(int signum, sighandler_t handler)
				Celon le signal recu, exectute une fonction handler personaliser.
				Voir man(7)signal pour voir tous les signaux possible ainsi que fonction safe d'utilisation dans un handler: http://manpagesfr.free.fr/man/man7/signal.7.html.

	-sigaction:	syntaxe: int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
				L'appel système sigaction() sert à modifier l'action effectuée par un processus à la réception d'un signal spécifique.

	-sigemptyset et sigaddset:	syntaxe: int sigemptyset(sigset_t *set)
										 int sigaddset(sigset_t *set, int signum)
								Ces fonctions permettent la manipulation des ensembles de signaux POSIX. 
	
	-kill:	syntaxe: int kill(pid_t pid, int sig)
			Permet d'envoyer un signal specifique a un pid.
			retourne 0 en cas de sucess et -1 en cas de fail.

	-exit:	syntaxe: void exit(int status)
			La fonction exit() termine normalement le processus et la valeur status & 0377 est renvoyée au processus parent.

	-getcwd:	syntaxe: char *getcwd(char *buffer, size_t size)
				La fonction getcwd() copie le chemin d'accès absolu du répertoire de travail courant dans la chaîne pointée par buf, qui est de longueur size.
				retourne NULL en cas d'erreur.
	
	-chdir:		syntaxe: int chdir(const char *path)
				chdir() remplace le répertoire de travail courant du processus appelant par celui indiqué dans le chemin path.
				retourne 0 en cas de sucess et -1 en cas d'erreur.
	
	-stat, lstat, fstat:	syntaxe: int stat(const char *path, struct stat *buff)
									 int fstat(int fd, struct stat *buff)
									 int lsatt(const char *path, struct stat *buf)
							Ces fonctions renvoient des informations à propos d'un fichier. Aucune permission n'est nécessaire sur le fichier lui-même, mais vous devez --- dans le cas de stat() et lstat() --- avoir la permission d'exécution (parcours) pour tous les répertoires de path qui mènent au fichier.
							stat() récupère l'état du fichier pointé par path et remplit le tampon buf.
							lstat() est identique à stat(), sauf que si path est un lien symbolique, il donne l'état du lien lui-même plutôt que celui du fichier visé.
							fstat() est identique à stat(), sauf que le fichier ouvert est pointé par le descripteur fd, obtenu avec open(2)
							la strcut de stat :
												struct stat {
															    dev_t     st_dev;      /* ID du périphérique contenant le fichier */
															    ino_t     st_ino;      /* Numéro inœud */
															    mode_t    st_mode;     /* Protection */
															    nlink_t   st_nlink;    /* Nb liens matériels */
															    uid_t     st_uid;      /* UID propriétaire */
															    gid_t     st_gid;      /* GID propriétaire */
															    dev_t     st_rdev;     /* ID périphérique (si fichier spécial) */
															    off_t     st_size;     /* Taille totale en octets */
															    blksize_t st_blksize;  /* Taille de bloc pour E/S */
															    blkcnt_t  st_blocks;   /* Nombre de blocs alloués */
															    time_t    st_atime;    /* Heure dernier accès */
															    time_t    st_mtime;    /* Heure dernière modification */
															    time_t    st_ctime;    /* Heure dernier changement état */
															};
							Ces fonction retourne 0 en cas de sucess et -1 en cas d'echec.
	
	-unlink:	syntaxe: int unlink(const char *pathname);
				unlink() détruit un nom dans le système de fichiers. Si ce nom était le dernier lien sur un fichier, et si aucun processus n'a ouvert ce fichier, ce dernier est effacé, et l'espace qu'il utilisait est rendu disponible.
				Si le nom était le dernier lien sur un fichier, mais qu'un processus conserve encore le fichier ouvert, celui-ci continue d'exister jusqu'à ce que le dernier descripteur le référençant soit fermé.
				Retourne 0 en cas de sucess et -1 en cas d'echec.
	
	-execve:	synataxe: int execve(cosnt char *filename, char *const argv[], char *const envp)
				execve() exécute le programme correspondant au fichier filename.
				filename correspond au binaire de la comande. ex : bin/cat
				*argv[] est un tableau de chaines de character qui corresponds aux argument de la commande et dois ce terminer par NULL. ex: [{"ls"}, {"-l"}, {NULL}]
				envp est simplement le path de notre machine.
				La fonction exit le processus(donc le processus ce termine) en cas de sucess, le resultat de la comande ce fera sur la sortie standard et retourne -1 en cas d'echec.

	-dup et dup2:	syntaxe: int dup(int oldfd)
							 int dup2(int oldfd, int newfd)
					dup() et dup2() créent une copie du descripteur de fichier oldfd.
					dup2() transforme newfd en une copie de oldfd, fermant auparavant newfd si besoin.
					ex : dup2(fd_monfichier, 0) ---> l'entre standard de ma machine devient mon fichier donc avec la fonction execve ma utiliser mon fichier pour utiliser la comande qu'on lui donne.
					Retourne 0 en cas de sucess et -1 en cas d'erreur.
	
	-pipe:	syntaxe: int pipe(int pipefd[2])
			pipe() crée un tube, un canal unidirectionnel de données qui peut être utilisé pour la communication entre processus. Le tableau pipefd est utilisé pour renvoyé deux descripteurs de fichier faisant référence aux extrémités du tube. pipefd[0] fait référence à l'extrémité de lecture du tube. pipefd[1] fait référence à l'extrémité d'écriture du tube. Les données écrites sur l'extrémité d'écriture du tube sont mises en mémoire tampon par le noyau jusqu'à ce qu'elles soient lues sur l'extrémité de lecture du tube. Pour plus de détails, voir pipe(7).
			Retourne 0 en cas de sucess et -1 en cas d'erreur.

	-opendir:	syntaxe: DIR *opendir(const char *name)
				La fonction opendir() ouvre un flux répertoire correspondant au répertoire name, et renvoie un pointeur sur ce flux. Le flux est positionné sur la première entrée du répertoire.
				La fonctions opendir() renvoie un pointeur sur le flux répertoire ou NULL si une erreur se produit

	-readdir:	syntaxe: struct dirent *readdir(DIR *dir)
				a fonction readdir() renvoie un pointeur sur une structure dirent représentant l'entrée suivante du flux répertoire pointé par dir.
				Elle renvoie NULL à la fin du répertoire, ou en cas d'erreur.
				struct dirent {
							      ino_t          d_ino;       /* numéro d'inœud */
							      off_t          d_off;       /* décalage jusqu'à la dirent suivante */
							      unsigned short d_reclen;    /* longueur de cet enregistrement */
							      unsigned char  d_type;      /* type du fichier */
							      char           d_name[256]; /* nom du fichier */
							  };
	
	-closedir:	syntaxe: int closedir(DIR *dir)
				La fonction closedir() ferme le flux de répertoire associé à dir. Après cette invocation, le descripteur dir du flux de répertoire n'est plus disponible.
				Renvoie 0 en cas de sucess et -1 en cas d'echec.
	
	-sterror:	syntaxe: char *sterror(int errnum)
				La fonction strerror() renvoie une chaîne décrivant le code d'erreur passé en argument errnum.

	-perror:	syntaxe: void perror(const char *s)
				La fonction perror() affiche un message sur la sortie d'erreur standard, décrivant la dernière erreur rencontrée durant un appel système ou une fonction de bibliothèque. D'abord, (si s n'est pas NULL et si *s n'est pas un octet nul), la chaîne de caractère s est imprimée, suivie d'un deux points (« : ») ou d'un blanc, puis le message, suivi d'un saut de ligne.
	
	-isatty:	syntaxe: int isatty(int desc)
				renvoie 1 si desc est un descripteur de fichier ouvert connecté à un terminal, ou 0 autrement.

	-ttyname:	syntaxe: char *ttyname(int fd)
				La fonction ttyname() renvoie un pointeur sur le chemin d'accès terminé par un octet nul du périphérique terminal ouvert associé au descripteur de fichier fd, ou NULL en cas d'erreur (par exemple si fd n'est pas connecté à un terminal). La valeur renvoyée peut pointer vers des données statiques, susceptibles d'être écrasées lors d'un appel ultérieur.

	-ttyslot:	syntaxe: int ttyslot(void)
				La fonction ttyslot() renvoie la position de l'entrée du terminal en cours dans un fichier.

	-ioctl:	syntaxe: int ioctl(int d, int requete, ...)
			La fonction ioctl() modifie le comportement des périphériques sous-jacents des fichiers spéciaux. En particulier, de nombreuses caractéristiques des fichiers spéciaux en mode caractère (par exemple des terminaux) peuvent être contrôlées avec des requêtes ioctl(). L'argument d doit être un descripteur de fichier ouvert.
			Le second argument est le code de la requête dépendant du périphérique. Le troisième argument est un pointeur non typé. Il est traditionnellement défini en char *argp (ceci date de l'époque avant que void * soit du C valide), et sera ainsi nommé dans le reste de cette page.
			Une requête ioctl() encapsule le fait que l'argument est un paramètre d'entrée ou de sortie ainsi que la taille de l'argument argp en octets. Les macros et constantes symboliques décrivant les requêtes ioctl() se trouvent dans le fichier <sys/ioctl.h>. 
			Renvoie 0 en cas de sucess et -1 en cas d'erreur.

	-getenv:	syntaxe: char *getenv(const char *name)
				La fonction getenv() recherche dans la liste des variables d'environnement un variable nommée name, et renvoie un pointeur sur la chaîne value correspondante.  
				Retourne le pointeur en cas de sucess et NULL en cas d'echec.

	-tcgetattr:	syntaxe: int tcgetattr(int fd, struct termios *termios_p)
				La fonction termios établissent une interface générale sous forme de terminal, permettant de contrôler les ports de communication asynchrone.
				struct de termios :
				{
					tcflag_t c_iflag;      /* modes d'entrée */
					tcflag_t c_oflag;      /* modes de sortie */
					tcflag_t c_cflag;      /* modes de contrôle */
					tcflag_t c_lflag;      /* modes locaux */
				}
				La routine tgetstr renvoie la chaîne de caractères correspondant à id, ou zéro si elle n'est pas disponible. Utilisez tputs pour sortir la chaîne retournée. La valeur de retour sera également copiée dans le tampon pointé par area, et la valeur de area sera mise à jour pour pointer au-delà du null terminant cette valeur. Cette fonction peut être appelée par un processus en arrière-plan ; néanmoins, les attributs de terminal peuvent être modifiés par la suite par le processus en avant-plan.
	
	-tgetent:	syntaxe: int tgetent(char *bp, const char *name)
				La routine tgetent charge l'entrée correspondant à nom. Elle renvoie 1 en cas de succès, 0 si cette entrée n'existe pas et -1 si la base de données terminfo n'a pas pu être trouvée. L'émulation ignore le pointeur de tampon bp

	-tgetflag:	syntaxe: int tgetflag(char *id)
				La routine tgetflag obtient l'entrée booléenne pour id, ou zéro si elle n'est pas disponible.
		
	-tgetnum:	syntaxe: int tgetnum(char *id)
				La routine tgetnum permet d'obtenir l'entrée numérique pour id, ou -1 si elle n'est pas disponible

	-tgetstr:	syntaxe: char *tgetstr(char *id, char **area)
				La routine tgetstr renvoie la chaîne de caractères correspondant à id, ou zéro si elle n'est pas disponible. Utilisez tputs pour sortir la chaîne retournée. La valeur de retour sera également copiée dans le tampon pointé par area, et la valeur de area sera mise à jour pour pointer au-delà du null terminant cette valeur.

	-tgoto:	syntaxe: char *tgoto(const char *cap, int col, int row)
				La routine tgoto instancie les paramètres dans la capacité donnée. La sortie de cette routine doit être transmise à tputs.
	
	-tputs:	syntaxe: int tputs(const char *str, int affcnt, int (*putc)(int))
			La routine tputs est décrite dans la page de manuel curs_terminfo(3X). Elle peut récupérer des capacités par nom termcap ou terminfo.

	-printf, malloc, free, write, open et read ne sont plus a presenter.

Header necessaire a toute ces fonctions :
											#include <unistd.h>
											#include <stdio.h>
											#include <stdlib.h>
											#include <fcntl.h>
											#include <signal.h>
											#include <string.h>
											#include <errno.h>
											#include <sys/time.h>
											#include <sys/resource.h>
											#include <sys/stat.h>
											#include <sys/types.h>
											#include <sys/wait.h>
											#include <sys/ioctl.h>
											#include <dirent.h>
											#include <termios.h>
											#include <curse.h>
											#include <term.h>
											#include <readline/readline.h>
											#include <readline/history.h>

II - Avant le Parsing

	1.Les variables d'environement.

Les variables d'environement sont disponible avec la commande env.
pour y avoir acces dans son programme il suffit d'ajouter l'argument **env dans le main:
												
									int	main(int argc, char **argv, char **env);

**env correspond alors a un tableau de chaine de character qui correspondent aux variables d'environement.

	2.Le PATH

Le PATH est present dans les variable d'environement il suffit alors de l'extraire de **env.

	3.Le Prompt

Le prompt correspond a l'inviter de commande, on peut utiliser la fonction readline(en theorie) ou un simple get_next_line.
ex :
	while ((line = get_next_line(0)) != NULL)
	{
  	parsing
  	write(0, "~$ ", 3);
	}

III - Le Parsing

	1.Potentiel structure

La structure auquel je pense est celle ci:

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	void			*data;
	int				type;
}	t_list;
(le nom de la struct doit changer)

Le principe d'une telle structure est d'avoir une liste doublement chainer ou chaque data correspond a une chaine de caracter, une pipe, une redirection ...
le type est simplement la pour nous dire comment utiliser la data de type void*
type {
	1 = word;
	2 = pipe;
	3 = redirection;
	...
}
On peut utiliser une strcuture de type enum pour le type.

	2.Les Separations

Les commandes séparées par un ';' sont exécutées successivement, l'interpréteur attend que chaque commande se termine avant de lancer la suivante.
un simple ft_split(line, ";") pourra nous premettre d'avoir les comande a executer sucessivement.
Puis dans le tableau de chaine de caractere fraichement creer on refais un split(instruction, " ");
Et on ajoute chaue chaine dans notre liste chainer

	3.Les Pipes

Simple, dans notre liste chaine si a un moment on a list.type == pipe, alors on regarde list.next.type == word et on execute alors notre pipe.
pour cela on va utiliser les fonction fork() afin de creer des enfants, la fonction pipe() afin qu'ils puissent communiquer entre eux, la fonction execve pour executer les commandes et la fonction dup2() pour rediriger l'entre et la sortie standard

	4.Comandes et arguments

Voir si la comande est dans nos builtin ou pas, si elle ne l'est pas la fonction execve sera utiliser.
La difficulter va etre de terminer le nombre d'argument d'une commande.
ex : echo -n bonjour
Normalement un split a ete fait decu et chaque chaine est dans une cellule de notre liste chaine.
on a 	argv[0] = echo -> commande
		argv[1] = -n -> argument (-lRa == -l-R-a)
		argv[2] = bonjour -> argument aussi.
une commande peut prendre un nombre d'argument potentiellement illimiter donc a gerer.

	5.Les protection

pour ': nombre impair de simple quote c’est pas bon, même si y a un \ (bash-3.2$ echo c'o\'u'cou)

pour ": les doubles quotes dans des simples quotes perdent leurs signification donc même si y a un nombre impair de doubles quotes c'est ok, même si y a un \ (bash-3.2$ echo co'c"o"u') (bash-3.2$ echo co'"c\"o"u')

pour $: ne conserve pas sa signification spéciale d’environnement (bash-3.2$ '$PATH')

pour \: ne conserve pas sa signification (bash-3.2$ echo bo'njou\$r')

Donc à l'intérieur d’une double quote :

    \\ : faut imprimer \
    \$ : faut imprimer $
    \” : faut imprimer “ :
    $ : faut appeler la variable d’environnement

	6.Les Redirection

rapel, 	0 = entre standard
		1 = sortie standard
		2 = sortie d'erreur

voyons les differente redirection:

	ls > liste_fichiers.txt  --->	créé le fichier liste_fichiers.txt et écrit la sortie dans le fichier
	ls >> liste_fichiers.txt --->	enregistré à la fin du fichier au lieu de l'écraser s'il existe déjà
	cat < notes.csv 		 --->	Permet de lire des données depuis un fichier et de les envoyer à une commande. Ici équivalent à écrire “cat notes.csv”

La redirection > creent le fichier si celui la n'exite pas.
La redirection >> ajoute en fin de fichier donc n'ecrase pas
La redirection < si le fichier n'existe pas il y a erreur
La redirection << a comme syntaxe , commande << LIMITER, c'est le principe du here_doc, ou l'entre standard est disponible pour l'user jusqu'a qu'il tape le limiter puis la commande donner s'effectue avec le contenu du here_doc.

