

// Deklaration einer Klasse
class RechneTotal {
  public:
    RechneTotal(int multiplikator);
    int total(int anzahl);
    int getMultiplikator();

  private:
    int _multiplikator;
}; 

extern RechneTotal rechneTotal;
