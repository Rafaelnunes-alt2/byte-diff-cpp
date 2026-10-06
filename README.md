# byte-diff-cpp

Comparador de arquivos em bytes, C++17, sem dependência. Primeiro byte
diferente mostra offset e hex dos dois lados. Limites de tamanho para não
mortar a memória.

## Uso

    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build -j
    ./build/byte-diff fileA fileB

Exit 0 se idêntico ou diff reportado, 1 em uso wrong, 2 em erro de I/O.

## Testes validados

    abc vs abd imprime offset=2 a=0x63 b=0x64 — OK
    abc vs abc imprime identical — OK
    arquivo inexistente exit 2 — OK

## Limitações

Mostra só a primeira diferença. Sem delta completo, sem patch,
sem contexto de bytes em volta. Somente leitura.

## Autor

Rafael Nunes — [@Rafaelnunes-alt2](https://github.com/Rafaelnunes-alt2)
