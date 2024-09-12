# Computaco de Alto Desempenho
Repositório de programas desenvolvidos para matéria PCS3568 - Sistemas de Computação de Alto Desempenho.
Objetivo da materia é entender na pratica e implementar conceitos de programacao paralela. 

Inicialmente nosso objetivo é acessar um computador remoto para executar programas que operam de forma sequencia e depois mensurar o desemepenho do mesmo programa caso ele fosse paralelizável. 

## Comando de acesso ao computador remoto

Os comandos utilizados aqui sao para acesso remoto utilizando um computador com macOS. Para realizar o acesso a maquina é necessria saber o ip da mesma e ter um login e uma senha autorizados e fornecidos pelo proprio administrador.

- Acesso ao computador remoto pela porta de entrada

  Os parametros utilizados nesse comando sao o usuario cadastrado de acesso, o ip do servidor e a porta de acesso.

   ```ssh usuario@ip-do-servidor -p porta ``` 
- Enviando arquivos para o servidor remoto pelo mac

  Caso voce esteja na mesma pasta que o arquivoce que voce queira enviar, basta colocar o nome do arquivo como parametro do caminho.
  
  ``` scp -P porta nome_arquivo usuario@ip-do-servidor:caminho_do_arquivo```


## Comandos de processamento no Linux

- Compilar um programa em C

  ```gcc –o nove_arquivo nome_arquivo.c ```

- Executar um programa em C
  
  ```./nome_arquivo```
- Comandos básicos para editar texto
  - Criar ou editar um arquivo de texto

    ```vi nome_do_arquivo.c```

    ou

    ```vim nome_do_arquivo.c```

  - Inserir caracteres 
 
    ```i```   
  - Excluir caracteres

    ```x```
  - Excluir linha

    ```dd```

  - Sair do modo de edicao

    ```ESC```
  - Salvar o arquivo

    ```w```
  - Fechar o arquivo

    ```q``` 

 - Mostrar os processos pendentes no linux

   ```ps -gaux```