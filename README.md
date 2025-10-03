Bounded Multi-Source Shortest Path (BMSSP)
📌 Descripción

El Bounded Multi-Source Shortest Path (BMSSP) es una variación del algoritmo clásico de caminos más cortos.
Se utiliza cuando:

Existen múltiples nodos fuente desde los cuales queremos calcular las distancias mínimas hacia todos los demás nodos.

Se establece una cota máxima de distancia (max_distance), de manera que solo nos interesa calcular caminos que no superen ese límite.

Este enfoque es útil en aplicaciones donde los caminos demasiado largos no son relevantes, como en redes de transporte, sistemas de recomendación, routing en redes o propagación de señales limitada.

📊 Características principales

Basado en Dijkstra multi-fuente.

Usa una cola de prioridad (min-heap) para elegir el nodo más cercano a expandir.

Mantiene un vector de distancias mínimas min_distance.

Ignora los caminos que superan el límite máximo de distancia (max_distance).

⚙️ Complejidad

Tiempo:

Similar a Dijkstra → O((V + E) log V), donde V = número de nodos, E = número de aristas.

Puede ser menor en la práctica porque se detiene temprano si la distancia supera max_distance.

Espacio:

O(V + E) por la lista de adyacencia y el vector de distancias.
