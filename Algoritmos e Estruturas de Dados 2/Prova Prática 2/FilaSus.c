//Daniel Salgado Magalhães - 821429

#include <stdio.h>

int main(){
    //leitura para saber quantos pacientes tem
    int numPaciente;

    //lê até não ter paciente
    while(scanf("%d", &numPaciente) != EOF){
        //cria um vetor com as informações de cada paciente, sendo numPaciente o número de linhas e 3 o número de atribuos, hora, minuto e tempo de condição
        int paciente[numPaciente][3];

        //preenche as informações de cada paciente
        for(int i=0;i<numPaciente;i++){
            int hora, minuto, condicao;
            scanf("%d %d %d", &hora, &minuto, &condicao);
            paciente[i][0] = hora;
            paciente[i][1] = minuto;
            paciente[i][2] = condicao;
        }

        //cálculo de condição crítica
        int criticos = 0;
        //verifica todos os pacientes
        for(int i=0; i<numPaciente;i++){
            int chegada = paciente[i][0]*60 + paciente[i][1]; // calcula os minutos do paciente hora*60+minutos
            int tempo = chegada + paciente[i][2]; //calcula o tempo máximo que tem para condição crítica

            //próximo paciente
            for(int j = i+1;j<numPaciente;j++){
                int proximaChegada = paciente[j][0] * 60+ paciente[j][1];
                //adiciona paciente[i][2], pois o tempo de espera do mesmo é muito alto
                if(proximaChegada >= tempo || (paciente[i][2] == 50)){
                    break;
                }
            criticos++;
            break;
            }
        }
        printf("%d\n", criticos);
    }
}