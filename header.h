struct TCarro {
  char dono[40];
  char modelo[45];
  char placa[15];
  float conta;
  int tipoDeCombustivel;
  float litros;
};

struct TCarro addCar(float gasolinaComum, float gasolinaAd, float etanol, float **bombaGasolinaComum, float **bombaGasolinaAd, float **bombaEtanol);

void addCarro(struct TCarro *carros, int *nCarrosFila, int fila, float gasolinaComum, float gasolinaAd, float etanol, float *bombaGasolinaComum, float *bombaGasolinaAd, float *bombaEtanol);

void abastecer(struct TCarro *carros, int *nCarrosFila, int fila, float *tLitrosVendidos, float *tVendas, int *tCarrosAtendidos, float *tLitrosVendidosGC, float *tVendasGC, float *tLitrosVendidosGA, float *tVendasGA, float *tLitrosVendidosET, float *tVendasET, bool *carroAbastecido);

void chamarCarro(bool *carroAbastecido, int nCarrosFila);

void relatorios(struct TCarro *carros, int nCarrosFila, float  bombaGasolinaComum, float bombaGasolinaAd, float bombaEtanol, float tLitrosVendidos, float tVendas, int tCarrosAtendidos, float tLitrosVendidosGC, float tVendasGC, float tLitrosVendidosGA, float tVendasGA, float tLitrosVendidosET, float tVendasET);

void addCombustivel(float *bombaGasolinaComum, float *bombaGasolinaAd, float *bombaEtanol);

void exibirCarros(struct TCarro *carros, int nCarrosFila);

void lerString(char *string, int tamanho);

void limpaBuffer();

void ll();