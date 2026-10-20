
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Funcion que ejecutara el hilo secundario */
void *cuentaDescendente(void *arg)
{
    int i;

    (void)arg;

    for (i = 10000; i >= 1; i--)
    {
        printf("Hilo secundario: %d\n", i);
    }

    return NULL;
}

int main(void)
{
    pthread_t hilo;
    int i;

    /* Crear el hilo secundario */
    if (pthread_create(&hilo, NULL, cuentaDescendente, NULL) != 0)
    {
        perror("Error al crear el hilo");
        return EXIT_FAILURE;
    }

    /* El proceso principal cuenta del 1 al 10000 */
    for (i = 1; i <= 10000; i++)
    {
        printf("Proceso principal: %d\n", i);
    }

    /* El proceso principal espera a que termine el hilo */
    if (pthread_join(hilo, NULL) != 0)
    {
        fprintf(stderr, "Error al esperar al hilo\n");
        return EXIT_FAILURE;
    }

    printf("\nEl hilo termino y el programa finalizo.\n");

    return EXIT_SUCCESS;
}
