package engtelecom.poo;

import java.rmi.RemoteException;

public class Contador implements ContadorDistribuido{
    public int valor = 0;
    
    public void incrementa() throws RemoteException {
        this.valor++;
    }
    public int obtemValor() throws RemoteException {
        return this.valor;
    }
}