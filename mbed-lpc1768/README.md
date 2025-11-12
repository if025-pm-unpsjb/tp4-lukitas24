# LPC1768

## Importar el proyecto en Eclipse
Una vez clonado localmente, agregar el proyecto en Eclipse:
* Seleccionar **[File > Import]** 
* En la nueva ventana:
    * Seleccionar **[C/C++] > Makefile Project with Existing Code]** y hacer clic en **[Next]**.
    * En **[Existing Code Location]** indicar el *path* al proyecto (usar el botón **[Browse...]**).
    * En **[Toolchain for Indexer]** seleccionar la opción *Arm Cross GCC* (¡importante!).

El proyecto debe aparecer ahora en la vista *Project Explorer*: 
* Hacer clic derecho sobre el mismo, y seleccionar **[Properties]** en el menú contextual.
* En la nueva ventana, en la sección izquierda, seleccionar **[C/C++ Build > Settings]**. En la sección derecha de la ventana, hacer clic en la pestaña **[Toolchains]**. Verificar que el campo *Name* indique *xPack GNU ARM Embedded GCC (arm-none-eabi-gcc)*.
* Hacer clic en **[Apply and Close]**.

---

## Compilar
Para compilar el proyecto hay tres alternativas:
* Hacer clic derecho sobre el proyecto en la vista *Project Explorer* y seleccionar **[Build]** en el menú contextual.
* Seleccionar en la barra de menúes de Eclipse **[Project > Build Project]**.
* Hacer clic en el ícono *Build* (un martillo).

Si el proyecto compilo correctamente, en la vista **[Console]** debe indicarse que se generó correctamente el archivo `build/blink.elf`.

---

## Configurar entorno PyOCD
Primero, verificar que el `pyocd-gdbserver` este correctamente configurado en Eclipse:
* Seleccionar **[Windows > Preferences]** en el menú de Eclipse.
* En la nueva ventana, seleccionar **[MCU > Global pyOCD Path]** en la lista izquierda.
* En el campo *Executable* debe indicar `pyocd` (con la extensión `.exe` en Windows), y el campo *Folder* debe contener el *path* al ejecutable (`~/setr/tools/pyocd/`).
* Hacer clic en **[Apply and Close]**.

A continuación se creará y ejecutará una configuración de *debug*:
* Seleccionar **[Run > Debug Configurations...]** en el menú de Eclipse.
* En la nueva ventana, hacer doble clic sobre **[GDB PyOCD debugging]** en el menú izquierdo. Esto crea una nueva configuración basada en este perfil, con el nombre del proyecto activo.
* Seleccionar el nuevo perfil creado (*mbed-blinky-makefile Default*).
* En el panel derecho:
    * En la pestaña **[Main]**, el campo *Project* debe indicar el nombre del proyecto. El campo *C/C++ Application* debe indicar el nombre del archivo ELF. Si no estuviera presente escribir el nombre del mismo, o bien hacer clic en el botón **[Search project]** o **[Browse]** para buscarlo.
    * En la pestaña **[Debugger]**, el campo *Executable* debe contener el valor `${pyocd_path}\${pyocd_executable}`. Estas dos variables son reemplazadas por los valores especificados el menú **[MCU > PyOCD]**.
    * En la pestaña **[Common]**, seleccionar la opción **[Shared file:]**, indicando en el campo el nombre del proyecto. De esta manera la configuración para debugging es guardada en un archivo `*.launch` dentro del proyecto.
    * Hacer clic en el botón **[Apply]**. No cerrar la ventana aún.
    
Para ejecutar el programa por primera vez, conectar la placa si no lo estuviera aún y, hacer clic en el botón **[Debug]**, que esta en la parte inferior de la ventana. Es posible que Eclipse pregunte si se desea cambiar a la perspectiva *Debug*, responder que sí.

---
    
## Próximas ejecuciones
Para cargar el programa en la placa y ejecutarlo, la opción más sencilla es hacer clic ícono **[Debug]** en la barra de herramientas de Eclipse, que ejecuta el último perfil seleccionado. Si se desea cambiar el perfil, hacer clic en la flecha que se encuentra junto al ícono **[Debug]**, y de la lista desplegable que se presenta, seleccionar el proyecto, o bien hacer clic en **[Debug Configurations...]**, que abre la ventana de configuración del punto anterior.



