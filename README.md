# Trabajo Práctico 3

Autor: Jorge Vasquez

## Componente a testear

Se trata de una biblioteca que implementa una MEF (mealy) para trabajar con anti-rebotes por software. Esta biblioteca sera utilizada en el proyecto final de la CESE para detectar el estado de un boton conectado a una placa nucleo-f4.

## Uso del repositorio

Este repositorio utiliza las siguientes herramientas:

1. [clang-format] () para el mantenimiento del formato del código escrito en lenguaje C
1. [pre-commit](https://pre-commit.com) para validaciones generales de formato del repositorio
1. [ceedling]() para ejecutar las pruebas unitarias en forma automatizada
1. [lcov]() para generar los informes de cobertura de las pruebas unitarias

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```
pre-commit install
```

Para ejecutar las pruebas unitarias se utiliza el siguiente comando:

```
ceedling test:all
```

Para generar el informe de cobertura de las pruebas se utiliza el siguiente comando:

```
ceedling clobber gcov:all utils:gcov
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc

```

Para compilar el proyecto se utiliza el siguiente comando:

```
make all

```
