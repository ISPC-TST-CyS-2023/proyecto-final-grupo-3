[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/PSenej-S)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=11289764)
# Integrantes
1 Carolina Nis
2 Fernando Vexenat
3 Alejando Leyton
4 William Leyton
5 Emilio Moyano
6 Maximo Santillan
## Proyecto-2
Proyecto del periodo 2: Controlador Universal, para la materia control y servicios  

## Definición del proyecto Sprint Planning 15/05/2023

ControladorMx El objetivo principal del proyecto es desarrollar un controlador universal llamado "ControladorMx" que permita recibir diferentes tipos de entradas, generar diferentes tipos de salidas y proporcionar una interfaz de visualización y ajuste mediante un display local.

#Objetivos del Proyecto:
Implementar un sistema versátil de entradas de control: El controlador debe ser capaz de aceptar sensores resistivos, entradas analógicas y digitales, y permitir la temporización para la entrada digital.
Desarrollar un sistema de salidas de control flexible: El controlador debe generar salidas PWM, salidas analógicas y digitales, permitiendo que cada salida defina una función lógica basada en las entradas digitales.
Crear una interfaz de usuario intuitiva y accesible: El sistema debe proporcionar un display local para la visualización de datos y ajuste del controlador. Este display permitirá la configuración de las características del controlador.
Asegurar la escalabilidad y la adaptabilidad del sistema: El sistema debe ser diseñado de tal manera que permita agregar nuevas funcionalidades y características en el futuro, manteniendo la facilidad de uso y la eficiencia en el control.
Desarrollo del Proyecto:
Definición 1 - Entradas de Control:
Las entradas de control estarán compuestas por sensores resistivos, entradas analógicas (0-10 v; 0-20 ma; 4-20ma), entradas digitales (asociadas a funciones de hasta 5 variables digitales), y temporización para la entrada digital. Se implementará una función de anti-bounce para las entradas digitales, evitando la interpretación errónea de las señales. Las entradas analógicas contarán con la capacidad de realizar conversiones de señales analógicas a digitales para su procesamiento posterior.

Definición 2 - Salidas de Control:
Las salidas de control estarán compuestas por PWM, salida analógica (0-10v; 0- 20ma; 4-20ma), y salida digital (cada una podrá definir una función lógica, cuyas

variables son las DI definidas como tales). Se implementará la posibilidad de temporizar las funciones, y se añadirá la posibilidad de variar la frecuencia de la salida PWM en función de una entrada analógica, lo que permitirá controlar la velocidad de un motor, por ejemplo.

Definición 3 - Visualización y Ajuste:
La visualización de los datos y el ajuste del ControladorMx se llevarán adelante mediante un display local i2c, que se encargará de la configuración de las características del controlador. Esto incluirá la habilitación de entradas y salidas, la configuración del modo de operación, y la definición de las funciones lógicas para las salidas digitales en función de las entradas digitales. Además, se proporcionará una interfaz intuitiva para el ajuste de parámetros como la frecuencia del PWM, y la posibilidad de vincular entradas y salidas específicas. Se considerará la inclusión de un sistema de ayuda en pantalla para facilitar la configuración del controlador por parte_de_lusuario. También se incorporara un panel, tipo display de reloj para visualización, temporización, otros.

El ControladorMx se diseñará con un enfoque en la escalabilidad y la adaptabilidad, permitiendo la inclusión de nuevas funcionalidades en el futuro.

## Metodología de Desarrollo:
Para este trabajo práctico, utilizaremos una metodología ágil de desarrollo. Esto implica una serie de sprints, cada uno de los cuales produce una parte funcional del proyecto. Las metodologías ágiles promueven el desarrollo iterativo y el constante feedback, lo que permite a los equipos adaptarse rápidamente a los cambios y mejorar la eficiencia del proyecto.

Resumen de la Metodología Scrum
Scrum es un marco de trabajo ágil que se utiliza principalmente para el desarrollo de software. Se basa en ciclos iterativos, llamados sprints, que suelen durar entre una y cuatro semanas. Aunque para este ejemplo, utilizaremos un sprint de una semana.

Scrum se basa en los siguientes eventos y roles:

• Product Owner: Es el responsable de maximizar el valor del producto y de gestionar el Product Backlog.

• Scrum Master: Facilita el proceso Scrum para el equipo, eliminando obstáculos que puedan impedir el progreso del equipo.

• Development Team: Equipo de profesionales que trabajan juntos para entregar incrementos de "producto terminado" en cada Sprint.

• Sprint Planning (Planificación del Sprint): Una reunión en la que el equipo decide qué se va a hacer durante el siguiente sprint.

• Daily Scrum: Una reunión diaria de 15 minutos en la que el equipo revisa el progreso hacia el objetivo del sprint y planea las actividades para las próximas 24 horas.

• Sprint Review (Revisión del Sprint): Una reunión en la que el equipo muestra lo que ha logrado durante el sprint.

• Sprint Retrospective (Retrospectiva del Sprint): Una reunión en la que el equipo reflexiona sobre el pasado sprint y propone mejoras para el siguiente.

## Hoja de Ruta del Sprint de dos semanas para el desarrollo de ControladorMx
Sprint Planning - Lunes 15/05/2023
Durante la reunión de Sprint Planning, se estableció el Product Backlog y luego se definió el Sprint Backlog, es decir, los elementos del Product Backlog que se trabajarán durante este sprint.

Daily Scrum - Martes 16/05/2023
Durante la reunión diaria, se determinó el backlog del sprint y se comenzó el desarrollo de las especificaciones del display. No se pudo seleccionar 3 Scrum Masters debido a la falta de concurrentes.

Daily Scrum - Miércoles 17/05/2023
En la reunión diaria, se eligieron 2 Scrum Masters: Leonardo González y Alfredo Palacios. Se presentaron problemas (issues) relacionados con la definición de los displays y se asignaron tareas para resolverlos.

Fin de semana (20/05 - 21/05)
Los fines de semana no se realizan reuniones formales de Scrum, pero el equipo puede continuar trabajando en sus tareas asignadas.

Daily Scrum – Viernes 2 de Junio
En la reunión diaria, se definió la metodología de trabajo para los Scrum Masters y el equipo Scrum. Se presentó la implementación de los prototipos de hardware.

Daily Scrum – Sabado 3 de Junio
En la reunión diaria, se revisará el progreso en la resolución de los problemas presentados el miércoles y se discutirán los siguientes pasos para el desarrollo de las especificaciones de las salidas.

Daily Scrum - Lunes 05/06/2023
En la reunión diaria del lunes, se revisará el progreso realizado durante el fin de semana y se discutirán las próximas tareas para continuar con el desarrollo de las especificaciones de las salidas.

Daily Scrum - Martes 06/06/2023 hasta Viernes 09/06/2023
Se continuarán las reuniones diarias, revisando el progreso y adaptando el plan de trabajo según sea necesario para lograr los objetivos del sprint. Se discutirá el desarrollo y prueba de la interfaz de usuario y la preparación para la revisión y retrospectiva del sprint.

Sprint Review - Sábado 10/06/2023 (Mañana)
En la revisión del sprint, el equipo mostrará lo que se ha logrado durante el sprint. Se presentará el trabajo completado y se obtendrá feedback.

Sprint Retrospective - Sábado 10/06/2023 (Tarde)
En la retrospectiva del sprint, el equipo reflexionará sobre el pasado sprint. Se discutirá lo que funcionó, lo que no funcionó y cómo se puede mejorar en el próximo sprint.

Desarrollo de un controlador universal. Ver Sprint.md para más detalles.
Desarrollo de un controlador universal. Ver [Sprint.md](ControladorMx/Desarrollo/Sprint.md) para más detalles.
## Organizacion de la estructura general del proyecto

ControladorMx
- Desarrollo
    - Documentacion  
    - SRC  
        - Implementacion  
        - Dashboard  
    - Assets  
        - img  
    - Sprint.md  
    - .gitignore  
    - LICENSE  
    - README.md         
- Comercial
    - Marketing  
    - Ventas
    - Demos
    - Documentacion
    - Legal
    - Branding
    - Multimedia
    - Presentaciones
    - README.md  
  
  
## Desarrollo
ControladorMx
- Desarrollo
    - Documentacion
        - README.md
    - SRC
        - Implementacion
            - Hardware
            - Software
            - Tests
            - Tools
            - README.md
        - Dashboard
            - Firmware
            - Backend
            - Frontend
            - Tests
            - Tools
            - README.md
        - README.md
    - Assets
        - img
        - README.md
    - Sprint.md
    - .gitignore
    - LICENSE
    - README.md

/documentacion: Esta carpeta contendría toda la documentación del proyecto, incluyendo la descripción del proyecto, guías de instalación y uso, y cualquier otra información útil para los desarrolladores y usuarios.

/src: Aquí se alojaría el código fuente del proyecto. Esta carpeta podría subdividirse en varias carpetas dependiendo de la arquitectura de tu aplicación. Por ejemplo:

/src/Implementacion: Hardware y Código para el dispositivo IoT. 
/src/Implementacion/Hardware: Prototipos de hardware, esquemas, etc.
/src/Implementacion/Software: Código fuente para el software que se ejecuta en el dispositivo IoT.
/src/Implementacion/Tests: Código para las pruebas de hardware y software.
/src/Implementacion/Tools: Cualquier script o herramienta auxiliar que se utilice en el desarrollo. 

/src/Dashboard: Código para el panel de control, si es que hay uno.
/src/Dashboard/firmware: Código del firmware para el dispositivo IoT.
/src/Dashboard/backend: Código para el servidor backend, si es que hay uno.
/src/Dashboard/frontend: Código para la interfaz de usuario, si es que hay una.
/src/Dashboard/Tests: Esta carpeta contendría todos los tests para el proyecto. Podría subdividirse en carpetas para tests de diferentes partes del sistema, como /tests/firmware, /tests/backend, y /tests/frontend.
/src/Dashboard/tools: Aquí podrías colocar cualquier script o herramienta auxiliar que se utilice en el desarrollo, como scripts para el despliegue, la configuración de la integración continua, etc.

/assets: Aquí se guardarían archivos adicionales que tu proyecto pueda necesitar, como imágenes, archivos de sonido, etc.

/Sprint.md: Este archivo contendría información sobre el ciclo de sprint actual, como las historias de usuario que se planean para el sprint, el trabajo que se ha completado, cualquier problema que haya surgido, etc.

.gitignore: Un archivo para decirle a Git qué archivos o carpetas debe ignorar.
LICENSE: Un archivo que especifica la licencia bajo la cual se distribuye tu proyecto.

README.md: Una descripción general de tu proyecto, cómo instalarlo y usarlo, y cualquier otra información que los usuarios o desarrolladores puedan necesitar.  


## Comercial
ControladorMx
- Comercial
    - Marketing
        - README.md     
    - Ventas
        - README.md
    - Demos
        - README.md
    - Documentacion
        - README.md
    - Legal
        - README.md 
    - Branding
        - README.md
    - Multimedia
        - README.md
    - Presentaciones
        - README.md
    - README.md

/MARKETING: Esta carpeta contendría todo el material de marketing, como folletos, presentaciones, infografías y otro contenido que promueva el dispositivo.

/Ventas: Aquí tendrías cualquier material de ventas que se utilizará para vender el dispositivo, como guiones de ventas, hojas de datos de productos, listas de precios, etc.

/Demos: Esta carpeta podría contener demostraciones en video del dispositivo en uso, tutoriales, y cualquier otro material que muestre cómo funciona el dispositivo.

/Documentacion: Aquí tendrías la documentación del usuario, que puede incluir manuales de usuario, guías de inicio rápido, preguntas frecuentes (FAQ), etc.

/Legal: Esta carpeta contendría cualquier documentación legal relacionada con el dispositivo, como términos de servicio, acuerdos de licencia de usuario final (EULA), políticas de privacidad, etc.

/Branding: Esta carpeta contendría elementos de marca como logotipos, paletas de colores, guías de estilo, etc.

/Multimedia: Aquí podrías almacenar fotos de alta calidad del producto, videos promocionales, y otros recursos visuales.

/Presentaciones: Aquí tendrías presentaciones de PowerPoint, Keynote o similares destinadas a diferentes audiencias (clientes, inversores, prensa, etc.).

/.gitignore: Un archivo para decirle a Git qué archivos o carpetas debe ignorar.

README.md: Una descripción general de tu proyecto, cómo instalarlo y usarlo, y cualquier otra información que los usuarios o desarrolladores puedan necesitar.


