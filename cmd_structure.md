## Structure pour chaque commande.
Une commande est considérée comme étant la chaine passée jusqu'à rencontrer un `;`

La structure se base sur un modèle de liste chaînée double.

```
typedef struct s_arg
{
    void    *next; // prochain argument
    void    *previous; // argument précédent
    char    *arg; // argument
}   t_arg;

typedef struct s_command
{
    void    *previous; // commande précédente
    void    *next; // commande suivante
    char    *name; // nom de commande (builtin) / exécutable
    t_arg   *arg; // liste chaînée, premier argument
    int input_fd; // fd d'entrée pour gérer pipe / redirect
    int output_fd; // fd de sortie pour gérer pipe / redirect
}   t_command;
```

Maybe ajouter un field `options` pour le "echo -n" par exemple
