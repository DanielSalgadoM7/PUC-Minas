public class Auxiliares { 
  public static void main(String[] args){

    class Celula {
    Contato contato;
    Celula prox;

    Celula() {
        this.contato = new Contato(); // novo ponteiro Contato
        this.prox = null; // ponteiro para null
    }

    Celula(Contato contato) {
        this.contato = contato;
        this.prox = prox;
    }
}
    //----------------------------------------------LISTA----------------------------------------------
    //Lista
    //inserção ou remoção no final da lista -  O(1)
    //inserção ou remoção em qualquer da lista -  O(n)
    //Quick e Merge são bons pra ordenar - O(n log n)
    class Lista{
      int[] array;
      int n;

      Lista(){this(6)}
      Lista(int tamanho){
        array = new[tamanho];
        n = 0;
      }
    }

    //Inserir no início da Lista
    void inserirInicio(int x) throws Exception{
      if(n >= array.length){
        throw new Exception("Erro!");
      }

      //levar elementos para o fim do array
      for(int i = n; i > 0; i--){
        array[i] = array[i-1];
      }
      array[0] = x;
      n++;
    }

    //Inserir no fim da Lista
    void inserirFim(int x) throws Exception{
      if(n >= array.length){
        throw new Exception("Erro!");
      }
      
      array[n] = x;
      n++;
    }

    //Inserir em qualquer lugar da lista
    void inserir(int x, int pos) throws Exception{
      if(n >= array.length || pos < 0 || pos > n){
        throw new Exception("Erro!");
      }
      
      //levar elementos para o fim do array
      for(int i = n; i > pos; i--){
        array[i] = array[i-1];
      }

      array[pos] = x;
      n++;
    }

    //Remover do início da Lista
    int removerInicio() throws Exception{
      if(n == 0){
        throw new Exception("Erro!");
      }
    
      int resp = array[0];
      n--;

      for(int i = 0; i < n; i++){
        array[i] = array[i+1];
      }
    
      return resp;
    }

    //Remover do fim da Lista
    int removerFim() throws Exception{
      if(n == 0){
        throw new Exception("Erro!");
      }
    
      return array[--n];
    }

    int remover(int pos) throws Exception{
      if(n == 0 || pos < 0 || pos >= n){
        throw new Exception("Erro!");
      }

      int resp = array[pos];
      n--;

      for(int i = pos; i < n; i++){
        array[i] = array[i=1];
      }

      return resp;
    }

    void mostrar(){
      System.out.print("[");
      for(int i = 0; i < n; i++){
         System.out.print(array[i] + " ");
      }
      System.out.print("]");
    }

	
    //----------------------------------------------LISTA FLEXÍVEL----------------------------------------------
	class Celula {
    public int elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    /**
     * Construtor da classe.
     */
    public Celula() {
        this(0);
    }

    /**
     * Construtor da classe.
     * 
     * @param elemento int inserido na celula.
     */
    public Celula(int elemento) {
        this.elemento = elemento;
        this.prox = null;
    }
}

class ListaFlexivel {
    private Celula primeiro;
    private Celula ultimo;

    /**
     * Construtor da classe que cria uma lista sem elementos (somente no cabeca).
     */
    public ListaFlexivel() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    /**
     * Insere um elemento na primeira posicao da lista.
     * 
     * @param x int elemento a ser inserido.
     */
    public void inserirInicio(int x) {
        Celula tmp = new Celula(x);
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if (primeiro == ultimo) {
            ultimo = tmp;
        }
        tmp = null;
    }

    /**
     * Insere um elemento na ultima posicao da lista.
     * 
     * @param x int elemento a ser inserido.
     */
    public void inserirFim(int x) {
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    /**
     * Remove um elemento da primeira posicao da lista.
     * 
     * @return resp int elemento a ser removido.
     * @throws Exception Se a lista nao contiver elementos.
     */
    public int removerInicio() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");
        }

        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        int resp = primeiro.elemento;
        tmp.prox = null;
        tmp = null;
        return resp;
    }

    /**
     * Remove um elemento da ultima posicao da lista.
     * 
     * @return resp int elemento a ser removido.
     * @throws Exception Se a lista nao contiver elementos.
     */
    public int removerFim() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");
        }

        // Caminhar ate a penultima celula:
        Celula i;
        for (i = primeiro; i.prox != ultimo; i = i.prox)
            ;

        int resp = ultimo.elemento;
        ultimo = i;
        i = ultimo.prox = null;

        return resp;
    }

    /**
     * Insere um elemento em uma posicao especifica considerando que o
     * primeiro elemento valido esta na posicao 0.
     * 
     * @param x   int elemento a ser inserido.
     * @param pos int posicao da insercao.
     * @throws Exception Se <code>posicao</code> invalida.
     */
    public void inserir(int x, int pos) throws Exception {

        int tamanho = tamanho();

        if (pos < 0 || pos > tamanho) {
            throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
        } else if (pos == 0) {
            inserirInicio(x);
        } else if (pos == tamanho) {
            inserirFim(x);
        } else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox)
                ;

            Celula tmp = new Celula(x);
            tmp.prox = i.prox;
            i.prox = tmp;
            tmp = i = null;
        }
    }

    /**
     * Remove um elemento de uma posicao especifica da lista
     * considerando que o primeiro elemento valido esta na posicao 0.
     * 
     * @param posicao Meio da remocao.
     * @return resp int elemento a ser removido.
     * @throws Exception Se <code>posicao</code> invalida.
     */
    public int remover(int pos) throws Exception {
        int resp;
        int tamanho = tamanho();

        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");

        } else if (pos < 0 || pos >= tamanho) {
            throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
        } else if (pos == 0) {
            resp = removerInicio();
        } else if (pos == tamanho - 1) {
            resp = removerFim();
        } else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox)
                ;

            Celula tmp = i.prox;
            resp = tmp.elemento;
            i.prox = tmp.prox;
            tmp.prox = null;
            i = tmp = null;
        }

        return resp;
    }

    /**
     * Mostra os elementos da lista separados por espacos.
     */
    public void mostrar() {
        System.out.print("[ ");
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.print(i.elemento + " ");
        }
        System.out.println("] ");
    }

    /**
     * Procura um elemento e retorna se ele existe.
     * 
     * @param x Elemento a pesquisar.
     * @return <code>true</code> se o elemento existir,
     *         <code>false</code> em caso contrario.
     */
    public boolean pesquisar(int x) {
        boolean resp = false;
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            if (i.elemento == x) {
                resp = true;
                i = ultimo;
            }
        }
        return resp;
    }

    /**
     * Calcula e retorna o tamanho, em numero de elementos, da lista.
     * 
     * @return resp int tamanho
     */
    public int tamanho() {
        int tamanho = 0;
        for (Celula i = primeiro; i != ultimo; i = i.prox, tamanho++)
            ;
        return tamanho;
    }
}
  //----------------------------------------------PILHA----------------------------------------------
  //First in Last Out
    class Pilha {
      int[] array;
      int topo;
  
      Pilha() {
          this(5);
      }
  
      Pilha(int tamanho) {
          array = new int[tamanho];
          topo = -1;
      }
  
      void empilhar(int x) throws Exception {
          if (topo == array.length - 1) {
              throw new Exception("Erro! Pilha cheia.");
          }
  
          topo++;
          array[topo] = x;
      }
  
      int desempilhar() throws Exception {
          if (topo == -1) {
              throw new Exception("Erro! Pilha vazia.");
          }
  
          int resp = array[topo];
          topo--;
          return resp;
      }
  
      void mostrar() {
          System.out.print("[ ");
          for (int i = topo; i >= 0; i--) {
              System.out.print(array[i] + " ");
          }
          System.out.println("]");
      }
  }

//----------------------------------------------PILHA FLEXÍVEL----------------------------------------------
  //First in Last Out
    class Pilha {
      private Celula topo;
  
      public Pilha() {
          topo = null;
      }
  
      public void inserir(int x){
	      Celula tmp = new Celula(x);
	      tmp.prox = topo;
	      topo = tmp;
	      tmp = null;
      }

	public void remover() throws Exception{
		if(topo == null)
			throw new Exception("Erro!");
		int elemento = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return elemento;
	}
  }

  //----------------------------------------------FILA----------------------------------------------
  //First in First Out
    class Fila(){
      int[] array;
      int primeiro, ultimo;

      Fila(){this(5);}

      Fila(int tamanho){
        array = new int[tamanho+1];
        primeiro = ultimo = 0;
      }
    }

    void inserir(int x) throws Exception{
      if(((ultimo+1)%array.length) == primeiro){
        throw new Exception("Erro!");
      }

      array[ultimo] = x;
      ultimo = (ultimo+1) % array.length;
    }

    void remover() throws Exception{
      if(primeiro == ultimo){
        throw new Exception("Erro!");
      }

      int resp = array[primeiro];
      primeiro = (primeiro+1)%array.length;
      return resp;
    }

    void mostrar(){
      int i = primeiro;
      System.out.println("[");

      while(i != ultimo){
        System.out.print(array[i] + "");
        i = (i+1) % array.length;
      }

      System.out.println("]");
    }

//----------------------------------------------FILA FLEXÍVEL----------------------------------------------
  class Celula {
    public int elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    /**
     * Construtor da classe.
     */
    public Celula() {
        this(0);
    }

    /**
     * Construtor da classe.
     * @param elemento int inserido na celula.
     */
    public Celula(int elemento) {
        this.elemento = elemento;
        this.prox = null;
    }
}

class FilaFlexivel {
    private Celula primeiro;
    private Celula ultimo;

    /**
     * Construtor da classe que cria uma fila sem elementos (somente no cabeca).
     */
    public FilaFlexivel() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    /**
     * Insere elemento na fila (politica FIFO).
     * @param x int elemento a inserir.
     */
    public void inserir(int x) {
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    /**
     * Remove elemento da fila (politica FIFO).
     * @return Elemento removido.
     * @throws Exception Se a fila nao tiver elementos.
     */
    public int remover() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover! Fila vazia.");
        }

        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        int resp = primeiro.elemento;
        tmp.prox = null;
        return resp;
    }

    /**
     * Mostra os elementos separados por espacos.
     */
    public void mostrar() {
        System.out.print("[ ");

        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.print(i.elemento + " ");
        }

        System.out.println("]");
    }
}
//----------------------------------------------MATRIZ FLEXÍVEL----------------------------------------------
	class Celula {
    public int elemento;
    public Celula inf, sup, esq, dir;
 
    public Celula(){
       this(0);
    }
 
    public Celula(int elemento){
       this(elemento, null, null, null, null);
    }
 
    public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir){
       this.elemento = elemento;
       this.inf = inf;
       this.sup = sup;
       this.esq = esq;
       this.dir = dir;
    }
 }

 class MatrizFlexivel{
   private Celula inicio;
   private int linha,coluna;
   public MatrizFlexivel(){
       this(3,3);
   }
   public MatrizFlexivel(int linhas, int colunas){
      inicio = new Celula(0);
      this.linha = linhas;
      this.coluna = colunas;
      Celula i = inicio;
      for(int j = 1; j< this.coluna; j++){
       Celula nova = new Celula(0);
       i.dir = nova;
       nova.esq = i;
       i = nova;
      }

      Celula linhaAnterior = inicio;
      for(int k = 1; k<this.linha; k++){
       Celula novaLinha = new Celula(0);
       linhaAnterior.inf = novaLinha;
       novaLinha.sup = linhaAnterior;

       Celula celulaAtualLinha = novaLinha;
       Celula celulaAcima = linhaAnterior;
       for(int j = 1; j<this.coluna; j++){
           Celula novaCelula = new Celula(0);
           celulaAtualLinha.dir = novaCelula;
           novaCelula.esq = celulaAtualLinha;

           celulaAcima = celulaAcima.dir;
           celulaAcima.inf = novaCelula;
           novaCelula.sup = celulaAcima;

           celulaAtualLinha=novaCelula;
       }
       linhaAnterior = novaLinha;
      }
       
   }
}
  //----------------------------------------------SELEÇÃO----------------------------------------------
  //O(n log n) - complexidade comparações de pior e médio caso
  //O(n^2) - complexidade ordenação
    for(int i = 0; i < (n-1); i++){
      int menor = i;
      for(int j = (i+1); j < n; j++){
        if(array[menor] > array[j]){
          comp++;
          menor = j;
        }
      }
      swap(menor, i);
      mov+=3;
    }

for(int i = 0; i < k; i++){
      int menor = i;
      for(int j = (i+1); j < n; j++){
        if(array[menor] > array[j]){
          comp++;
          menor = j;
        }
      }
      swap(menor, i);
      mov+=3;
    }

  //----------------------------------------------INSERÇÃO----------------------------------------------
  //Melhor caso (comparações e movimentações) - array ordenado O(n)
  //Pior caso (comparações e movimentações) - ordem decrescente O(n^2)
//avaliação para registros na ordem crescente é o melhor
// estável
    for(int i = 1; i < n; i++){
      int tmp = array[i];
      int j = i-1;
      while((j>=0) && (array[j] > tmp)){
        array[j+1] = array[j];//Deslocamento
        j--;
      }
      array[j+1] = tmp;
    }

    for(int i = 1; i < n; i++){
      int tmp = array[i];
      int j = (i<k)?i-1:k-1;
      while((j>=0) && (array[j] > tmp)){
        array[j+1] = array[j];//Deslocamento
        j--;
      }
      array[j+1] = tmp;
    }

  //----------------------------------------------BOLHA----------------------------------------------
  //O(n^2) - complexidade comparações de pior e médio caso
  //O(n^2) - complexidade ordenação
		for (int i = (n - 1); i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (array[j] > array[j + 1]) {
               swap(j, j+1);
				}
			}
		}

  //----------------------------------------------SHELLSORT---------------------------------------------
  //Melhor caso (comparações e movimentações) - array ordenado O(nlogn)
  //Pior caso (comparações e movimentações) - ordem decrescente O(n^2)
	void shellsort(){
		int h = 1;
		do{
			h = (h*3) + 1
		}while(h<n);
		do{
			h/=3;
			for(int cor=0; cor<h;cor++){
				insercaoPorCor(cor, h);
			}
		}while(h != 1);
	}

	void insercaoPorCor(int cor, int h){
		for(int i = (h+cor); i<n;i+=h){
			int tmp = array[i];
			int j = i-h;
			while((j>=0) && (array[j]>tmp)){
				array[j+h] = array[j];
				j -= h;
			}
			array[j+h] = tmp;
		}
	}

//----------------------------------------------QUICKSORT---------------------------------------------
  //Melhor caso (comparações e movimentações) - divide o array sistematicamente 0(n logn)
  //Pior caso (comparações e movimentações) - pivot é o menopr ou o maior elemnento do array, eliminando um elemento em cada chamada 0(n^2)
// não estável	
//primeira chamada é 0 e n-1
//avaliação para registros na ordem aleatória e ordem decrescente é o melhor
	void quicksort(int esq, int dir){
		int i = esq, j = dir, pivo = array[(esq+dir)/2];
		while(i<=j){
			while(array[i] < pivo)
				i++;
			while(array[j]>pivo)
				j--;
			if(i<=j){
				swap(i, j);
				i++;
				j--;
			}
		}
		if(esq < j)
			quicksort(esq, j);
		if(i<dir)
			quicksort(i, dir);
	}

void quicksort(int esq, int dir){
		int i = esq, j = dir, pivo = array[(esq+dir)/2];
		while(i<=j){
			while(array[i] < pivo)
				i++;
			while(array[j]>pivo)
				j--;
			if(i<=j){
				swap(i, j);
				i++;
				j--;
			}
		}
		if(esq < j)
			quicksort(esq, j);
		if(i<k && i < dir)
			quicksort(i, dir);
	}

//----------------------------------------------MERGESORT---------------------------------------------
  //Todos os casos 0(n logn)
	public static void MERGEsort(int[] array, int n) {
      mergesort(0, n-1, array);
   }

   /**
    * Algoritmo de ordenacao Mergesort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
    */
   private static void mergesort(int esq, int dir, int[] array) {
      if (esq < dir){
         int meio = (esq + dir) / 2;
         mergesort(esq, meio, array);
         mergesort(meio + 1, dir, array);
         intercalar(esq, meio, dir, array);
      }
   }

   /**
    * Algoritmo que intercala os elementos entre as posicoes esq e dir
    * @param int esq inicio do array a ser ordenado
    * @param int meio posicao do meio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
    */ 
   public static void intercalar(int esq, int meio, int dir, int [] array){
      int n1, n2, i, j, k;

      //Definir tamanho dos dois subarrays
      n1 = meio-esq+1;
      n2 = dir - meio;

      int[] a1 = new int[n1+1];
      int[] a2 = new int[n2+1];

      //Inicializar primeiro subarray
      for(i = 0; i < n1; i++){
         a1[i] = array[esq+i];
      }

      //Inicializar segundo subarray
      for(j = 0; j < n2; j++){
         a2[j] = array[meio+j+1];
      }

      //Sentinela no final dos dois arrays
      a1[i] = a2[j] = 0x7FFFFFFF;

      //Intercalacao propriamente dita
      for(i = j = 0, k = esq; k <= dir; k++){
         array[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
      }
   }

//----------------------------------------------HEAPSORT---------------------------------------------
  //Todos os casos 0(n log n)	
	 public static void heapsort(int[] array, int n) {
        // Contrucao do heap
        for (int tamHeap = 2; tamHeap <= n; tamHeap++) {
            construir(tamHeap, array);
        }

        // Ordenacao propriamente dita
        int tamHeap = n;
        while (tamHeap > 1) {
            swap(array, 0, tamHeap - 1);
            tamHeap--;
            reconstruir(tamHeap, array, 0);
        }
    }

    public static void construir(int tamHeap, int[] array) {
        for (int i = tamHeap - 1; i > 0 && array[i] > array[(i - 1) / 2]; i = (i - 1) / 2) {
            swap(array, i, (i - 1) / 2);
        }
    }

    public static void reconstruir(int tamHeap, int[] array, int i) {
        while (2 * i + 1 < tamHeap) {
            int filho = getMaiorFilho(i, tamHeap, array);
            if (array[i] < array[filho]) {
                swap(array, i, filho);
                i = filho;
            } else {
                break;
            }
        }
    }

    public static int getMaiorFilho(int i, int tamHeap, int[] array) {
        int filho;
        if (2 * i + 1 == tamHeap - 1 || array[2 * i + 1] > array[2 * i + 2]) {
            filho = 2 * i + 1;
        } else {
            filho = 2 * i + 2;
        }
        return filho;
    }


public static void heapsort(int[] array, int n) {
        // Contrucao do heap
        for (int tamHeap = 2; tamHeap <= k; tamHeap++) {
            construir(tamHeap, array);
        }

        // Ordenacao propriamente dita
	for(int i = k+1;i<=n;i++){
		if(array[i] < array[1]){
			swap(i,1);
			reconstruir(k);
		}
	}

	int tam=k;
	while(tam>1){
		swap(1, tam--);
		reconstruir(tam);
	}
    }

    public static void construir(int tamHeap, int[] array) {
        for (int i = tamHeap - 1; i > 0 && array[i] > array[(i - 1) / 2]; i = (i - 1) / 2) {
            swap(array, i, (i - 1) / 2);
        }
    }

    public static void reconstruir(int tamHeap, int[] array, int i) {
        while (2 * i + 1 < tamHeap) {
            int filho = getMaiorFilho(i, tamHeap, array);
            if (array[i] < array[filho]) {
                swap(array, i, filho);
                i = filho;
            } else {
                break;
            }
        }
    }

    public static int getMaiorFilho(int i, int tamHeap, int[] array) {
        int filho;
        if (2 * i + 1 == tamHeap - 1 || array[2 * i + 1] > array[2 * i + 2]) {
            filho = 2 * i + 1;
        } else {
            filho = 2 * i + 2;
        }
        return filho;
    }

//----------------------------------------------COUNTINGSORT---------------------------------------------
  //Todos os casos 0(n log n)
//O counting sort não pode ser aplicado adequadamente na ordenação de strings e números reais
//No caso das strings, temos um problema combinatório para identificar a posição de cada string no array de contagem
//No caso dos números reais, temos infinitos valores entre dois números inteiros
//Complexidade O(n)
// estável	
public static void coutingsort(int[] array, int n) {
        // Array para contar o numero de ocorrencias de cada elemento
        int[] count = new int[getMaior(array, n) + 1];
        int[] ordenado = new int[n];

        // Inicializar cada posicao do array de contagem
        for (int i = 0; i < count.length; count[i] = 0, i++)
            ;

        // Agora, o count[i] contem o numero de elemento iguais a i
        for (int i = 0; i < n; count[array[i]]++, i++)
            ;

        // Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for (int i = 1; i < count.length; count[i] += count[i - 1], i++)
            ;

        // Ordenando
        for (int i = n - 1; i >= 0; ordenado[count[array[i]] - 1] = array[i], count[array[i]]--, i--)
            ;

        // Copiando para o array original
        for (int i = 0; i < n; array[i] = ordenado[i], i++)
            ;
    }

    public static int getMaior(int[] array, int n) {
        int maior = array[0];

        for (int i = 0; i < n; i++) {
            if (maior < array[i]) {
                maior = array[i];
            }
        }
        return maior;
    }
//----------------------------------------------RADIXSORT---------------------------------------------
  //Todos os casos 0(n)
public class RadixSort {

    public static void countingSortByDigit(int[] array, int n, int exp) {
        // Array para contar o número de ocorrências de cada dígito (0-9)
        int[] count = new int[10];
        int[] output = new int[n];

        // Inicializar cada posição do array de contagem
        for (int i = 0; i < 10; count[i] = 0, i++);

        // Contar ocorrências de cada dígito
        for (int i = 0; i < n; i++) {
            int index = (array[i] / exp) % 10;
            count[index]++;
        }

        // Agora, o count[i] contém o número de elementos menores ou iguais a i
        for (int i = 1; i < 10; count[i] += count[i - 1], i++);

        // Ordenando
        for (int i = n - 1; i >= 0; i--) {
            int index = (array[i] / exp) % 10;
            output[count[index] - 1] = array[i];
            count[index]--;
        }

        // Copiando para o array original
        for (int i = 0; i < n; array[i] = output[i], i++);
    }

    public static void radixSort(int[] array, int n) {
        // Encontra o maior número para saber o número de dígitos
        int max = getMaior(array, n);

        // Aplica o counting sort para cada dígito
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSortByDigit(array, n, exp);
        }
    }

    public static int getMaior(int[] array, int n) {
        int maior = array[0];

        for (int i = 1; i < n; i++) {
            if (maior < array[i]) {
                maior = array[i];
            }
        }
        return maior;
    }
}

//----------------------------------------------ÁRVORE----------------------------------------------
//Custo de inserção, remoção e pesquisa nas listas 0(n)
//Custo de pesquisa na lista sequencial ordenada 0(nlogn), inserção e remoção são 0(n)


class No{
	int elemento;
	No esq;
	No dir;
	No (int elemento){
		this(elemento, null, null);
	}
	No(int elemento, No esq, No dir){
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
	}
}

class ArvoreBinaria{
	No raiz;
	ArvoreBinaria(){
		raiz = null;
	}

	void inserir(int x) throws Exception{
		raiz = inserir(x, raiz);
	}
	
	No inserir(int x, No i) throws Exception{
		if(i == null){
			i = new No(x);
		}else if(x < i.elemento){
			i.esq = inserir(x, i.esq);
		}else if(x > i.elemento){
			i.dir = inserir(x, i.dir);
		}else{
			throw new Exception("Erro!");
		}
		return i;
	}

	//Melhor Caso - 0(1)
	//Pior Caso - 0(n)
	void inserirPai(int x) throws Exception{
		if(raiz == null){
			raiz = new No(x);
		}else if(x < raiz.elemento){
			inserirPai(x, raiz.esq, raiz);
		}else if(x > raiz.elemento){
			inserirPai(x, raiz.dir, raiz);
		}else{
			throw new Exception("Erro!");
		}
	}

	void inserirPai(int x, No i, No pai) throws Exception{
		if( i == null){
			if(x<pai.elemento){
				pai.esq = new No(x);
			}else{
				pai.dir = new No(x);
			}
		}else if(x < i.elemento){
			inserirPai(x, i.esq, i);
		}else if(x > i.elemento){
			inserirPai(x, i.dir, i);
		}else{
			throw new Exception("Erro!");
		}
	}

	//Melhor Caso - 0(1)
	//Pior Caso - 0(n)
	boolean pesquisar(int x){
		return pesquisar(x, raiz);
	}

	boolean pesquisar(int x, No i){
		boolean resp;
		if( i == null){
			resp = false;
		}else if(x < i.elemento){
			resp = true;
		}else if(x > i.elemento){
			resp = pesquisar(x, i.esq);
		}else{
			resp = pesquisar(x, i.dir);
		}
		return resp;
	}

	//Caso geral - 0(n)
	//central ou em ordem
	void caminharCentral(No i){
		if(i!=null){
			caminharCentral(i.esq);
			System.out.print(i.elemento + "");
			caminharCentral(i.dir);
		}
	}

	//pós-fixado ou pós-ordem
	void caminharPos(No i){
		if(i!=null){
			caminharPos(i.esq);
			caminharPos(i.dir);
			System.out.print(i.elemento + "");
		}
	}

	//pré-fixado ou pré-ordem
	void caminharPre(No i){
		if(i!=null){
			System.out.print(i.elemento + "");
			caminharPre(i.esq);
			caminharPre(i.dir);
		}
	}


	//Melhor Caso - 0(1)
	//Pior Caso - 0(n)
	void remover(int x) throws Exception{
		raiz = remover(x, raiz);
	}

	No remover(int x, No i)throws Exception{
		if( i == null){
			throw new Exception("Erro!");
		}else if(x < i.elemento){
			i.esq = remover(x, i.esq);
		}else if(x > i.elemento){
			i.dir = remover(x, i.dir);
		}else if(i.dir == null){
			i = i.esq;
		}else if(i.esq == null){
			i = i.dir;
		}else{
			i.esq = maiorEsq(i, i.esq);
		}
		return i;
	}

	No maiorEsq(No i, No j){
		if(j.dir == null){
			i.elemento = j.elemento;
			j = j.esq;
		}else{
			j.dir = maiorEsq(i, j.dir);
		}
		return j;
	}
}
  //----------------------------------------------FIM----------------------------------------------
  }
}

//Exercício Resolvido - retorna a altura da árvore
int getAltura(No i, int altura){
	if(i == null){
		altura--;
	}else{
		int alturaEsq = getAltura(i.esq, altura+1);
		int alturaDir = getAltura(i.dir, altura+1);
		altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
	}
	return altura;
}

//Exercício Resolvido - retorna o numero de elementos pares existentes na árvore
public int numPares(){
	return numPares(raiz);
}
public int numPares(No i){
	int resp = 0;
	if(i!=null){
		resp = ((i.elemento % 2 == 0) ? 1 : 0) + numPares(i.esq) + numPares(i.dir);
	}
	return resp;
}

//Exercício Resolvido - retorna o numero de elementos pares existentes na árvore
No toAB(Celula p1, CelulaDupla p2){
	No resp = null;
	p1 = p1.prox;
	p2 = p2.prox;
	while(p1 != null && p2 != null){
		resp = inserir(resp, p1.elemento);
		resp = inserir(resp, p2.elemento);
		p1 = p1.prox;
		p2 = p2.prox;
	}

	while(p1 != null){
		resp = inserir(resp, p1.elemento);
		p1 = p1.prox;
	}

	while(p2 != null){
		resp = inserir(resp, p2.elemento);
		p2 = p2.prox;
	}
	return resp;
}

No inserir(No i, int x) throws Exception{
	if(i == null){
		i = new No(x);
	}else if(x < i.elemento){
		i.esq = inserir(x, i.esq);
	}else if(x > i.elemento){
		i.dir = inserir(x, i.dir);
	}else{
		throw new Exception("Erro!");
	}
	return i;
}


public class ArvoreArvore {
	private No raiz; // Raiz da arvore.

	/**
	 * Construtor da classe.
	 */
	public ArvoreArvore() {
		raiz = null;
      inserir('M');
      inserir('T');
      inserir('F');
      //os outros 23 caracteres.
	}

   public void inserir(char letra){
      //igualzinho (mesmo, de verdade) ao da árvore binária padrão!!!
   }


   public void inserir(String s){
      inserir(s, raiz);
   }

   public void inserir(String s, No i) throws Exception {
		if (i == null) {
         throw new Exception("Erro ao inserir: caractere invalido!");

      } else if (s.charAt(0) < i.elemento) {
         inserir(x, i.esq);

      } else if (s.charAt(0) > i.elemento) {
         inserir(x, i.dir);

      } else {
         i.outro = inserir(s, i.outro);
      }
   }


	private No2 inserir(String s, No2 i) throws Exception {
		if (i == null) {
         i = new No2(x);

      } else if (s.compareTo(i.elemento) < 0) {
         i.esq = inserir(x, i.esq);

      } else if (s.compareTo(i.elemento) > 0) {
         i.dir = inserir(x, i.dir);

      } else {
         throw new Exception("Erro ao inserir: elemento existente!");
      }

		return i;
	}


   public void mostrar(){
      mostrar(raiz);
   }

   public void mostrar(No i){
      if (i != null){
         mostrar(i.esq);
         //System.out.println("Letra: " + i.elemento);
         mostrar(i.outra);
         mostrar(i.dir);
      }
   }

   public void mostrar(No2 i){
      if (i != null){
         mostrar(i.esq);
         System.out.println(i.elemento);
         mostrar(i.dir);
      }
   }



   public boolean hasStringTam10(){
      return hasStringTam10(raiz);
   }

   public boolean hasStringTam10(No i){
      boolean resp = false;
      if(i != null){
         resp = hasStringTam10(i.outro) || hasStringTam10(i.esq) || hasStringTam10(i.dir);
      }
      return resp;
   }

   public boolean hasStringTam10(No2 i){
      boolean resp = false;
      if(i != null){
         resp = i.elemento.length() == 10 || hasStringTam10(i.esq) || hasStringTam10(i.dir);
      }
      return resp;
   }


   public boolean hasStringTam10(char c){
      return hasStringTam10(raiz, c);
   }

   public boolean hasStringTam10(No i, char c){
      boolean resp;
		if (i == null) { 
         resp = false;

      } else if (c < i.elemento) { 
         resp = hasStringTam10(i.esq, c); 

      } else if (c > i.elemento) { 
         resp = hasStringTam10(i.dir, c); 
      
      } else { 
         resp = hasStringTam10(i.outro); 
      }
      return resp;
   } 





	/**
	 * Metodo publico iterativo para pesquisar elemento.
	 * @param elemento Elemento que sera procurado.
	 * @return <code>true</code> se o elemento existir,
	 * <code>false</code> em caso contrario.
	 */
	public boolean pesquisar(String elemento) {
		return pesquisar(raiz, elemento);
	}

	private boolean pesquisar(No no, String x) {
      boolean resp;
		if (no == null) { 
         resp = false;

      } else if (x.charAt(0) < no.elemento) { 
         resp = pesquisar(no.esq, x); 

      } else if (x.charAt(0) > no.elemento) { 
         resp = pesquisar(no.dir, x); 
      
      } else { 
         resp = pesquisarSegundaArvore(no.outro, x); 
      }
      return resp;
	}

	private boolean pesquisarSegundaArvore(No2 no, String x) {
      boolean resp;
		if (no == null) { 
         resp = false;

      } else if (x.compareTo(no.elemento) < 0) { 
         resp = pesquisarSegundaArvore(no.esq, x); 

      } else if (x.compareTo(no.elemento) > 0) { 
         resp = pesquisarSegundaArvore(no.dir, x); 

      } else { 
         resp = true; 
      }
      return resp;
	}


   public int contPalavra(char letra){
      return contPalavra(letra, raiz);
   }

   public int contPalavra(char letra, No i) throws Exception {
      int resp = 0;

		if (i == null) {
         throw new Exception("Erro ao pesquisar: caractere invalido!");

      } else if (letra < i.elemento) {
         resp = contPalavra(letra, i.esq);

      } else if (letra > i.elemento) {
         resp = contPalavra(letra, i.dir);

      } else {
         resp = contPalavra(i.outro);
      }

      return resp;
   }

   public int contPalavra(No2 i){
      int resp = 0;
      if(i != null){
         resp = 1 + contPalavra(i.esq) + contPalavra(i.dir);
      }
      return resp;
   }
}


public class Agenda {
	private No raiz; 

	public Agenda() {
		raiz = new No ('M');
		raiz.esq = new No ('G');
		raiz.dir = new No ('T');
		raiz.esq.esq = new No ('A');
		//inserir todas as 26 letras do alfabeto...
	}

	public boolean pesquisarNome(String nome) {
		return pesquisarNome(raiz, nome);
	}

	private boolean pesquisarNome(No no, String nome) {
      boolean resp;
		if (no == null) { 
         resp = false;
      } else if (Char.toUpper(nome.charAt(0)) == no.letra) { 
         resp = false;
         for(Celula i = no.primeiro.prox; (!resp && i != null); i = i.prox){
            if(i.contato.nome.equals(nome) == true){
               resp = true;
            }
         }
      } else if (Char.toUpper(nome.charAt(0)) < no.letra) { 
         resp = pesquisarNome(no.esq, nome); 

      } else { 
         resp = pesquisarNome(no.dir, nome); 
      }
      return resp;
	}

	public void inserir(Contato contato) throws Exception {
		if(Character.isLetter(contato.nome.charAt(0))){
			raiz = inserir(raiz, contato);	
		} else {
			throw new Exception("Erro ao inserir!");
		}
	}

	private No inserir(No no, Contato contato) throws Exception {
		// insere o nó com a letra
		if (no == null) {
			no = new no(Character.toUpperCase(contato.nome.charAt(0)));
			no.ultimo.prox = new Celula(contato);
			no.ultimo = no.ultimo.prox;	
		
		// insere o contatinho
		} else if (Character.toUpperCase(contato.nome.charAt(0)) == no.letra) { 
			no.ultimo.prox = new Celula(contato);
			no.ultimo = no.ultimo.prox;
		
		// letra menor, caminha para a esquerda
		} else if (Character.toUpperCase(contato.nome.charAt(0)) < no.letra) { 
			no.esq = inserir(no.esq, contato);

		// letra maior, caminha para a direita
		} else { 
			no.dir = inserir(no.dir, contato);
		}
		return no;
	}
	
	public boolean pesquisar(int cpf) {
		return pesquisar(raiz, cpf);
	}

	private boolean pesquisar(No no, int cpf) {
		boolean resp = false;
		if (no != null) {
			resp = pesquisar(no.primeiro.prox, cpf);
			if(resp == false){
				resp = pesquisar(no.esq, cpf);
				if(resp == false){
					resp = pesquisar(no.dir, cpf);
				}
			}
		}
		return resp;
	}

	private boolean pesquisar(Celula i, int cpf){
		//efeuar a pesquisa na lista a partir do i
	}

}


class Celula {
   Contato contato;
   Celula prox;

   public Celula (){
      this(null, null);
   }

   public Celula(Contato contato){
      this(contato, null);
   }

   public Celula (Contato contato, Celula prox){
      this.contato = contato;
      this.prox = prox;
   }
}


class Contato {
   public String nome;
   public String telefone;
   public String email;
   public int cpf;

   public Contato(){
      this("","","",-1);
   }
   public Contato(String nome, String telefone, String email, int cpf){
      this.nome = nome;
      this.telefone = telefone;
      this.email = email;
      this.cpf = cpf;
   }
}

class No {
	public char letra;
	public No esq, dir;
	public Celula primeiro, ultimo;
	
	public No(char letra) {
		this.letra = letra;
		this.esq = this.dir = null;
		primeiro = ultimo = new Celula();
	}
}

/*Questões Abertas (V ou F)-> 

1- O custo de pesquisa em uma arvore binaria nunca será linear.: 
Falso, se a ordem de inserção em uma arvore for, o proximo maior que o anterios, ou ao contrario
seu custo será linear, O(n). 
pesquisa/inserção:
BST não balanceada-> O(1) melhor caso e O(n) pior caso
BST balanceada-> O(log) ambos casos


2- Toda arvore binaria de pesquisa com mais de 0 elementos, está organizada em formato heap ou heap invertido.:
falso, o heal/heap invertido garantem q os filhos serão menores que os pais, ou que os filhoes serão maiores que os pais
ja em uma arvore BST, a organização deve garantir que os menores estejam à esquerda e os maiores Á direita.


3- A ordem de complexidade do QUICKsort no pior caso será quadratica.: 
verdadeiro, O(n^2), ocorre quando o pivot escolhido é o maior elemento ou o menor elemento
O(n log n) no melhor caso, quando divide o array em partes iguais


4- O custo de pesquisa em uma arvore BALANCEADA, nunca pode ser linear.: 
verdadeiro, o custo de pesquisa de uma arvore binaria é O(log n)


5- O melhor algoritmo em termo de movimentações é o SELEÇãO, cuja complexidade é O(n log n).:
Falso, o algoritmo de SELEÇãO tem complexidade de O(n^2) e realiza 3N - 3 movimentações, devido ao swap, o melhor 
algotitmo seria o inserção, com complexidade de O(n²) no pior caso e O(n) no melhor caso. é um algoritmo ESTAVEL e 
realizaria 0 movimentações	


6- Se um array estiver pré-ordenado, o melhor metodo de ordenação seria o de inserção, com complexidade no melhor 
caso de O(n.):
verdadeiro, O algoritmo de inserção é o melhor para arrays pré ordenados pois nunca iria percorrer o arry mais de uma vez, 
tendo complexidade de O(n) melhor caso


7- No pior caso, a ordem de complexidade do HEAPsort sera quadratica:
falso, a complexidade do HEAPsort em todos os casos é O(n log n)


8- A ordem de complexidade do algoritmo de bolha sempre será de O(n^2), independente da ordenação inicial:
falso, se o array estiver previamente ordenado, a complexidade será de O(n), mas em seu pior e caso medio 
será de O(N^2)

9- mergesort O(n log n) pois sempre divide o array pela metade, ordena sub array, ESTAVEL.

	1- questão ARVORE de ARVORE) criar metodo contarPalavra que recebe 2 caracteres e conta o numero de palavras que começam com o 
primeiro caractere e terminam com o ultimo: 
class arvore{
    No raiz;
    (...)
    int pesquisar(char primeiro, char ultimo)
    {
        No no = pesquisar(primeiro, this.raiz);
        if(no == null || no.raiz == null)
        {
            return 0;
        }
        return contar(ultimo, no.raiz);
    }

    int contar(char ch, No2 i)
    {
        if(i != null)
        {
            int j = (ch == i.palavra.charAt(i.palavra.()-1))?1:0;
            j+=contar(ch, i.esq);
            j+=contar(ch, i.dir);
            return j;
        }
        return 0;
    }

    int contarPorNivel(char ch, no2 raiz)
    {
        int cont = 0;
        Queue<No2> fila = new Queue<x>;
        fila.add(raiz);
        while(!fila.isEmpty())
        {
            no2 no = fila.poll();
            if(no.palavra.chatAt(no.palavra.sin()-1)==ch)
            {
                cont ++;
            }
            if(no.esq !=null)
            {
                fila.add(no.esq);
            }
            if(no.dir !=null)
            {
                fila.add(no.dir);
            }
        }
        return cont;
    }
}


2- questao matriz flexivel em C) ordenar decrescente e adicionar na lista que esta na matriz:
checarArvore(No * Noarvore, Celula cabeça, int pesquisado)
{
    if(NoArvore == null)
    {
        return;
    }
    if(pesquisado < NoArvore -> numero)
    {
        checarArvore(NoArvore->esq, cabeça, pesquisado);
    }
    else if(pesquisado > NoArvore-> numero)
    {
        checarArvore(NoArvore->dir, cabeça, pesquisado);
    }
    else { inserirCelula(cabeça, pesquisado)}
}

Celula * econtraRepetido(No * raiz, CelulaMatriz * inicio)
{
    Celula * cabeça = malloc(sizeof(Celula));

    CelulaMatriz * tempLinha = inicio;
    while(tempLinha != null)
    {
        CelulaMatriz * tempColuna = tempLinha;
        while(tempColuna != null)
        {
            checarArvore(raiz, cabeçam tempColuna->numero);
            tempColuna = tempColuna-> prox;
        }
        tempLinha = tempLinha->inf;
    }
    return cabeça;
}

void inserirCelula(Celula cabeça, int chave)
{
    Celula * temp = cabeça;
    Celula * ins = malloc(sizeof(Celula));
    ins-> numero = chave;

    while(temp->prox != null)
    {
        if(chave > temp->prox.numero)
        {
            Celula * op = temp->prox;
            temp->ins;
            ins->prox = op;
            return;
        }
        temp = temp->prox;
    }
    temp->prox = ins;
}

3- percorrer uma matriz flexivel, e em cada no da matriz tem uma lista, remover os numero impares da lista: 
import java.util.Iterator;
public void caminhar() {
        Celula atual = matriz[0][0]; // Começar pela célula superior esquerda
        while (atual != null) {
            // Realize alguma operação com a célula atual
            atual.removerImpar();
            
            // Navegar para a próxima célula na linha
            if (atual.prox != null) {
                atual = atual.prox;
            } else {
                // Mover para a próxima linha
                if (atual.baixo != null) {
                    atual = atual.baixo;
                    // Ir para o início da linha
                    while (atual.ant != null) {
                        atual = atual.ant;
                    }
                } else {
                    // Fim da matriz
                    break;
                }}}}

public void removerImpar() {
        Iterator<Integer> it = valores.iterator();
        while (it.hasNext()) {
            if (it.next() % 2 != 0) {
                it.remove();
            }}}

4- Implementar treesort e falar a complexidade:
public void insert(int value) {
        root = insertRec(root, value);
    }
    private TreeNode insertRec(TreeNode root, int value) {
        if (root == null) {
            root = new TreeNode(value);
            return root;
        }
        if (value < root.value) {
            root.left = insertRec(root.left, value);
        } else if (value > root.value) {
            root.right = insertRec(root.right, value);
        }
        return root;
    }
    public void inorderTraversal(TreeNode node, List<Integer> sortedList) {
        if (node != null) {
            inorderTraversal(node.left, sortedList);
            sortedList.add(node.value);
            inorderTraversal(node.right, sortedList);
        }
    }
Complexidade de O(n log n) melhor caso e O(n^2) pior caso.

5- Lista de Pilha, percorrer a lista , depois Percorrer a pilha em cada CelulaLista e retornar no final qual das pilhas tem mais elementos
//contar elementos da pilha
int contarElementos() {
        int contador = 0;
        CelulaPilha atual = topo;
        while (atual != null) {
            contador++;
            atual = atual.prox;
        }
        return contador;}
//pilha com mais elementos
CelulaLista encontrarPilhaComMaisElementos() {
        CelulaLista atual = inicio;
        CelulaLista pilhaMaior = null;
        int maxElementos = 0;

        while (atual != null) {
            int quantidade = atual.contarElementos();
            if (quantidade > maxElementos) {
                maxElementos = quantidade;
                pilhaMaior = atual;
            }
            atual = atual.prox;
        }
        return pilhaMaior;}      
    
6- Arvore de Arvore em JAVA, pegar uma palavra chave de referencia, Contar quantas palavras na arvore de arvores começam com a letra da palavra
chave e tem a mesma quantidade de caracteres: 

NoChar buscar(String palavra) {
        char letra = palavra.charAt(0);
        NoChar no = buscarRec(raiz, letra);
        if (no != null) {
            int count = contarPalavras(no, palavra.length());
            System.out.println(count);
        } else {
            System.out.println("letra nao existe.");
        }
        return no;
    }
    private NoChar buscarRec(NoChar raiz, char letra) {
        if (raiz == null || raiz.letra == letra) {
            return raiz;
        }
        if (letra < raiz.letra) {
            return buscarRec(raiz.esquerda, letra);
        }
        return buscarRec(raiz.direita, letra);
    }

    private int contarPalavras(NoChar no, int tamanho) {
        int contador = 0;
        NoPalavra atual = No.palavras;
        while (atual != null) {
            if (atual.palavra.length() == tamanho) {
                contador++;
            }
            atual = atual.prox;
        }
        return contador;
    }

7- metodo que recebe 2 arrays e retorna 1 só ordenado: 

public static int[] vetorOrdenado(int[] vetA, int[] vetB) {
        int[] arrayCombinado = new int[vetA.length + vetB.length];
        for (int i = 0; i < vetA.length; i++) {
            combinedArray[i] = vetA[i];}

        for (int i = 0; i < vetB.length; i++) {
            combinedArray[vetA.length + i] = vetB[i];}

        // Ordenar o array combinado com inserção pois uma parte ja esta ordenada
        for(int i = 1; i < arrayCombinado.length; i++)
        {
            int temp = arrayCombinado[i];
            while(int j = i - 1; j >= 0 && arrayCombinado[j]>temp)
            {
                arrayCombinado[j+1] = arrayCombinado[j];
                j--;
            }
            arrayCombinado[j+1] = temp;}
        return combinedArray;}
    
8- Numa agenda de contados, pesquisar pelo nome e cpf da pessoa.:
public String pesquisarNo(String nome, No i) throws Exception{
        String resp = "false";
        char letra = Character.toUpperCase(nome.charAt(0));
        if(i == null){
            throw new Exception("Arvore vazia");
        }else if(i.getLetra() > letra){
            pesquisarNo(nome, i.getNoesq());
        }else if(i.getLetra() < letra){
            pesquisarNo(nome, i.getNodir());
        }else{
            resp = i.pesquisarContato(nome);
        }
        return resp;
    }

public String pesquisarNo(String cpf, No i) throws Exception {
    String resp = "Contato não encontrado";
    if (i == null) {
        throw new Exception("Árvore vazia");
    } else if (i.getCpf().compareTo(cpf) > 0) {
        resp = pesquisarNo(cpf, i.getNoesq());
    } else if (i.getCpf().compareTo(cpf) < 0) {
        resp = pesquisarNo(cpf, i.getNodir());
    } else {
        resp = i.pesquisarContato(cpf);
    }
    return resp;
}

9- caminha por uma matriz flexivel considerando que já temos os contrutores feitos e retorna a posição caso encontre um valor:
public void caminhaMatriz(int valor) {
        matrizNo linhaTemp = inicio;
        int i , j;   i = j = 0;
        while (linhaTemp != null) {
            matrizNo colunaTemp = linhaTemp; 
            while (colunaTemp != null) {
            System.out.println("Matriz Pos [" + i + "][" + j + "]:");
                if (colunaTemp.root != null) {
                    colunaTemp.printRoot(); // Printa a BST associada ao nó
                    if (colunaTemp.buscar(valor)) {
                        System.out.println("Valor " + valor + " encontrado na posição [" + i + "][" + j + "].");
                        return true;
                    }
                }
                colunaTemp = colunaTemp.right; // Vai para a direita
                j++;
            }
            linhaTemp = linhaTemp.down; // Vai para baixo
            i++;
            j = 0;
        }return false;}
