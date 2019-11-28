#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

//Variáveis de entrada

int op, mat_func, qtd_dep, plan_mod;
float sal_base, sal_bruto, sal_ext, sal_liq;
char dep, vt, plan_saude;


// Variáveis de cálculo

float calc_vt, vt_max, desc_vt, calc_plan, calc_fgts, calc_inss, sal_fam, calc_fam, sal_ir, dep_ir, alq_ir, parc_ir, calc_ir;

// Variáveis de saída

float tot_venc, tot_desc, tot_liq;

// Contadores

int i, cont;

// Vetores

int age_dep[10];



// >>> ROTINAS <<<



// 0 - CADASTRO DA FOLHA

void cadastro () {
	printf("\n--------------------------------------");
	printf("\n====== CADASTRO DE FUNCIONÁRIO =======");
	printf("\n--------------------------------------");
	printf("\n\nInforme a matrícula do funcionário: .................... ");
	scanf("%d", &mat_func);
	printf("\n\nO Funcionário possui dependentes? (S/N): ............... ");
	dep = getche();
	//printf("\nVoce selecionou '%c'", dep);
	if (dep == 's' || dep == 'S')  {
		printf("\n\nInforme a quantidade de dependentes: ................... ");
		scanf("%d", &qtd_dep);
		for (i=1; i<(qtd_dep)+1; i++) {
			printf("\n\nInforme a idade do dependente %d: ....................... ", i);
			scanf("%d", &age_dep[i]);
		}	
	}
	
	else {
		printf("\n\nNão possui dependentes.");
	}
	
	printf("\n\nInforme o salário base do funcionário: ................. R$ ");
	scanf("%f", &sal_base);
	printf("\n\nInforme o salário extra / gratificações do funcionário:  R$ ");
	scanf("%f", &sal_ext);
	sal_bruto = (sal_base + sal_ext);
	//printf("\n\nO salário bruto é: R$%.2f ", sal_bruto);	
}


// 1 - VALE TRANSPORTE

void VT() {
	printf("\n\nOfuncionário faz uso de VT? (S/N): ..................... ");
	vt = getche();
	//printf("\nVoce selecionou: %c", vt);
	vt_max = 198;
	if (vt == 's') {
		calc_vt = (sal_bruto * 0.06);
		if (calc_vt <= 198) {
			desc_vt = (sal_bruto * 0.06);
			//printf("\n\nO desconto do VT é: R$%.2f ", desc_vt);			
		}
		else {
			desc_vt = 198;
			//printf("\n\nO desconto do VT é: R$%.2f ", desc_vt);
		}
	}
	else {
		calc_vt = 0;
		//printf("\n\nNão recebe VT.");
	}
}


// 2 - PLANO DE SAÚDE

void PS() {
	printf("\n\nO funcionário faz uso do Plano de Saúde? (S/N): ........ ");
	plan_saude = getche();
	//printf("\nVoce selecionou: %c", plan_saude);
	if (plan_saude == 's' || plan_saude == 'S') {
		printf("\n\nOptante por qual modalidade? 1 - para Enfermaria ou 2 - para Quarto: ");
		scanf("%d", &plan_mod);
		if (plan_mod == 1) {
			calc_plan = 89.90;
			printf("\n\nO desconto do Plano de Saúde é: R$%.2f ", calc_plan);
		}
		if (plan_mod == 2) {
			calc_plan = 119.90;
			printf("\n\nO desconto do Plano de Saúde é: R$%.2f ", calc_plan);
		}
		
	}
	if (plan_saude == 'n' || plan_saude == 'N') {
		calc_plan = 0;
		printf("\n\nNão usa Plano de Saúde.");
	}
	
}


// 3 - FGTS

void FGTS() {
	calc_fgts = (sal_bruto * 0.08);
	printf("\n\nO valor de FGTS à ser depositado é: R$%.2f ", calc_fgts);
}


// 4 - INSS

void INSS(){
	if (sal_bruto <= 2919.72) {
		calc_inss = (sal_bruto * 0.09);
		printf("\n\nDesconto de INSS: R$%.2f ", calc_inss);
	}
	else {
		if (sal_bruto <= 5839.45) {
			calc_inss = (sal_bruto * 0.11);
			printf("\n\nDesconto de INSS: R$%.2f ", calc_inss);
		}
		else {
			if (sal_bruto > 5839.45) {
				calc_inss = (sal_bruto * 0.11);
				printf("\n\nDesconto de INSS: R$%.2f ", calc_inss);
			}
		}
	
	}
}


// 5 - SALÁRIO FAMÍLIA

void SF() {
	if (dep == 's' || dep == 'S') {		
		if (sal_bruto <= 907.77) {
			if (age_dep[i] <= 14) {
				sal_fam = 46.54;
				printf("\n\nO valor do Salário Família é: R$%.2f ", sal_fam);
			}
		}
		else {
			if (sal_bruto <= 1364.43) {
				if (age_dep[i] <= 14) {
				sal_fam = 32.80;
				printf("\n\nO valor do Salário Família é: R$%.2f ", sal_fam);
			}
			else {
				if (sal_bruto > 1364.43) {
				sal_fam = 0;
				printf("\n\nNão hápto para receber Salário Família.")	;
				}
			}
		}	
	}
	
}

if (dep == 'n' || dep == 'N') {
		sal_fam = 0;
		printf("\nNão recebe salário família.");
	}

}


// 6 - IMPOSTO DE RENDA

void IR() {
	// cálculo de desconto por dependentes menores de 21 anos (desconto de R$ 189.59 por dependente)
cont = 0;
if (dep == 's' || dep == 'S')	 {
	dep_ir = 189.59;
	for (i=0; i<(age_dep[i] <= 21)+1; i++) {
			cont++;					
	}
	
	dep_ir *= cont; 
	
	printf("\n\nO valor da dedução do IR sobre dependentes é: R$%.2f ", dep_ir);
}

else {
	printf("\n\nNão possui dedução de IR por dependentes.");
}
	
	
	// valor do IR - sal_bruto - calc_inss - dep_ir.
	
	sal_ir = (sal_bruto - calc_inss - dep_ir);
	printf("\n\nO salário de cálculo para IR é: R$%.2f ", sal_ir);
	
	// alíquota e parcela do IR
	
	if (sal_ir <= 1903.98) {
		alq_ir = 0;
		parc_ir = 0;
		calc_ir = 0;
		printf("\n\nIsento de IR.");
	}
	else {
		if (sal_ir <= 2826.65) {
			alq_ir = sal_ir * 0.075;
			parc_ir = 142.80;
			calc_ir = (alq_ir - parc_ir);
			printf("\n\nValor do IR à ser debitado em folha: R$%.2f ", calc_ir);
			}
			
			else {
				if (sal_ir <= 3751.05) {
				alq_ir = sal_ir * 0.15;
				parc_ir = 354.80;
				calc_ir = (alq_ir - parc_ir);
				printf("\n\nValor do IR à ser debitado em folha: R$%.2f ", calc_ir);
				}
				
				else {
					if (sal_ir <= 4664.68) {
					alq_ir = sal_ir * 0.225;
					parc_ir = 636.13;
					calc_ir = (alq_ir - parc_ir);
					printf("\n\nValor do IR à ser debitado em folha: R$%.2f ", calc_ir);
					}
					
					else {
						if (sal_ir > 4664.68) {
						alq_ir = sal_ir * 0.275;
						parc_ir = 869.36;
						calc_ir = (alq_ir - parc_ir);
						printf("\n\nValor do IR à ser debitado em folha: R$%.2f ", calc_ir);
						}
					}					
				}			
			}		
		}

}


// 7 - SALÁRIO LÍQUIDO

void SL() {
	
	// sal_bruto - calc_vt - calc_plan - calc_inss + sal_fam - calc_ir
	sal_liq = (sal_bruto - calc_vt - calc_plan - calc_inss + sal_fam - calc_ir);
	printf("\n\nO salário líquido do funcionário é : R$%.2f ", sal_liq);
	
	
}


// 8 - MONTAGEM DA FOLHA DE PAGAMENTO

void FOLHA() {
	tot_venc = (sal_base + sal_ext + sal_fam);
	tot_desc = (calc_vt + calc_plan + calc_inss + calc_ir);
	tot_liq = (tot_venc - tot_desc);
	printf("\n\n========================================================================");
	printf("\n\n========================= FOLHA DE PAGAMENTO ===========================");
	printf("\n\n========================================================================");
	printf("\n\nMatrícula do Funcionário: %d", mat_func);
	printf("\n\n---------------------------------");
	printf("\n\n                                              Proventos    Descontos");
	printf("\n------------------------------------------------------------------------");
	printf("\nSalário Báse:                                 R$ %.2f", sal_base);
	printf("\nExtras/Gratif.:                               R$ %.2f", sal_ext);
	printf("\nSalário Família:                              R$ %.2f", sal_fam);
	printf("\nFGTS:                                         R$ %.2f", calc_fgts);
	printf("\nVale-Transporte:                                           R$ %.2f", desc_vt);
	printf("\nPlano de Saúde:                                            R$ %.2f", calc_plan);
	printf("\nINSS:                                                      R$ %.2f", calc_inss);
	printf("\nImposto de Renda:                                          R$ %.2f", calc_ir);
	printf("\n\nTotal Vencimentos: R$ %.2f", tot_venc);
	printf("\nTotal de Descontos: R$ %.2f", tot_desc);
	printf("\n\nTOTAL LÍQUIDO: R$ %.2f", tot_liq);
	printf("\n------------------------------------------------------------------------");
}


int main (void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	do {
		system("cls");
		cadastro();
		//system("cls");
		VT();
		//system("cls");
		PS();
		system("cls");
		FGTS();
		INSS();
		SF();
		IR();
		SL();
		system("cls");
		FOLHA();
		
		printf("\n\nDeseja continuar registrando Folhas de Pagamento? 1 para SIM ou 0 para NÃO: ");
		scanf("%d", &op);
	} while (op == 1);

	
}

