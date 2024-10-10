# Computacao de Alto Desempenho
Repositório de programas desenvolvidos para matéria PCS3568 - Sistemas de Computação de Alto Desempenho.
Objetivo da materia é entender na pratica e implementar conceitos de programacao paralela. 

Inicialmente nosso objetivo é acessar um computador remoto para executar programas que operam de forma sequencia e depois mensurar o desemepenho do mesmo programa caso ele fosse paralelizável. 

## Comando de acesso ao computador remoto

Os comandos utilizados aqui sao para acesso remoto utilizando um computador com macOS. Para realizar o acesso a maquina é necessria saber o ip da mesma e ter um login e uma senha autorizados e fornecidos pelo proprio administrador. Os parametros escritos em <span style="color:#35f235"> verde</span> devem ser substituidos por seu valor ao executar o comando. 

- Acesso ao computador remoto pela porta de entrada

  Os parametros utilizados nesse comando sao o usuario cadastrado de acesso, o ip do servidor e a porta de acesso.

  <code>ssh <code style="color:#35f235" >usuario</code>@<code style="color:#35f235" >ip-do-servidor</code>  -p <code style="color:#35f235" >porta </code> </code>

- Enviando arquivos para o servidor remoto pelo mac

  Caso voce esteja na mesma pasta que o arquivoce que voce queira enviar, basta colocar o nome do arquivo como parametro do caminho.
  
  <code>scp -P <code style="color:#35f235">porta nome_arquivo usuario</code>@<code style="color:#35f235">ip-do-servidor</code>:<code style="color:#35f235">caminho_do_arquivo</code></code>


## Comandos de processamento no Linux
Os parametros escritos em <span style="color:#35f235"> verde</span> devem ser substituidos por seu valor ao executar o comando. 

- Compilar um programa em C

  Para compilar os programas escritos em C utilizamos <a href="https://gcc.gnu.org/">GCC</a> que é um compilador de código aberto que serve para converter arquivos-fonte em arquivos executáveis.

  - Compilar um programa

      <code>gcc –o <span style="color:green">nove_arquivo_gerado nome_arquivo_compilado </span> </code>

   - Compilar com otimizacao 

      <code>gcc -O3 –o <code style="color:#35f235">nove_arquivo_gerado nome_arquivo_compilado </code></code>

  - Compilar programas habilitando threads

    <code>gcc -O3 –o <code style="color:#35f235">nove_arquivo_gerado nome_arquivo_compilado </code> -lpthead</code>

   - Compilar programas utilizando a biblioteca OpenMP

      <a href="https://www.openmp.org/">OpenMP </a> é uma interface de programação de aplicações (API) que permite a programação multi-processo de memória compartilhada em várias plataformas.

      <code>gcc –o <code style="color:#35f235">nove_arquivo_gerado nome_arquivo_compilado </code> -fopenmp</code>
  
- Compilar um programa utilizando Cpar

  <a href="https://www.teses.usp.br/teses/disponiveis/3/3141/tde-02102024-102626/pt-br.php">Cpar </a>é uma linguagem de programação para processamento paralelo, desenvolvida na Escola Politécnica da Universidade de São Paulo. Para compilar um programa atraves dessa ferramenta ele deve estar no mesmo diretorio da ferramente e utilizar o seguinte comando para executar o script.

  <code>./compila-cpar<code style="color:#35f235">nove_arquivo</code> </code>

  Isso vai gerar um arquivo executavel de mesmo nome. Por questoes esteticas, o script disponivel nesse repositorio na aula 03  foi ligeramente modificado.

- Executar um programa compilado
  
  <code>./<code style="color:#35f235">nome_arquivo_gerado</code></code>
- Comandos básicos para editar texto
  - Criar ou editar um arquivo de texto

    <code>vi <code style="color:#35f235">nome_do_arquivo.c </code></code>

    ou

    <code> vim <code style="color:#35f235">nome_do_arquivo.c </code></code>

  - Inserir caracteres 
 
    <code>i</code>   

  - Excluir caracteres

    <code>x</code>

  - Excluir linha

    <code>dd</code>
    
  - Sair do modo de edicao

    <code>ESC</code>

  - Salvar e fechar o arquivo

    <code>:wq</code>

 - Mostrar os processos pendentes no linux

   <code> ps -gaux</code>

- Finalizar o processo 

   <code> kil <code style="color:#35f235">numero_do_processo</code></code>

- Listar conteúdo do diretório
  
  Caso o comando seja executado sem parametro, o direotirio atual será listado.

   <code> ls <code style="color:#35f235">nome_do_diretorio</code></code>

- Criar diretório

   <code> mkdir <code style="color:#35f235">nome_do_diretorio</code></code>

- Mudar de diretório

  Caso o parametro seja <code>..</code> o comando retornara para o diretorio acima. 

   <code> cd <code style="color:#35f235">nome_do_diretorio</code></code>

- Copiar arquivo

   <code> cp <code style="color:#35f235"> nome_do_arquivo nome_do_diretorio</code></code>

- Remover arquivo

   <code> rm <code style="color:#35f235">nome_do_arquivo</code></code>

