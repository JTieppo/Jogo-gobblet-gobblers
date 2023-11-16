#include <stdio.h>    // importa biblioteca padrão do C para utilização de funções principais
#include <locale.h>   // importa biblioteca para utilizar caracteres em português
#include <string.h>   // importa biblioteca de tratamento de strings
#include <stdbool.h>  // importa biblioteca boleana para verdadeiro e falso 

#include <allegro5/allegro.h>             // importa biblioteca padrão e geral do allegro5
#include <allegro5/allegro_primitives.h>  // importa biblioteca primitives para desenhar formas na tela
#include <allegro5/allegro_ttf.h>         // importa biblioteca para tratamento de desenho de texto
#include <allegro5/allegro_audio.h>       // importa biblioteca para tratamento de audio 
#include <allegro5/allegro_acodec.h>      // importa biblioteca para tratamento de mídia audio 

int main() { 
    setlocale(LC_ALL, "Portuguese");

    // PONTOS DE DESTAQUE
    // Todo o código foi criado dentro da main por ser ela quem inicia a interface e as bibliotecas, por isso os voids pertencem a ela
    // Criei o código pensando na organização que facilite a manutenção, por isso tem seções de código
    // geralmente a seção é identificada pelos comentarios acima e as funções de cada linha ao lado direito
    // os printf utilizei para pontos que podem ser melhorados pois aparecem só no terminal, mas fiquem a
    // vontade pra implementar novas ideias
    // Utilizei o allegro5 como biblioteca GUI


    // Inicia e armazena as bibliotecas do allegro5 com a chamada das funções das mesmas
    al_init();                  // inicia a biblioteca padrao do allegro
    al_init_primitives_addon(); // contem draw circle e rectangle
    al_init_ttf_addon();        // contem load do ttf pras fontes
    al_init_font_addon();       // contem a biblioteca de escrita pra fonte
    al_install_audio();         // contem a biblioteca de load audio
    al_init_acodec_addon();     // contem a biblioteca de tratamento de audio e midia
    al_reserve_samples(1);      // reserva memória para midia audio

    // cria ponteiro para uma janela e eventos(display)
    ALLEGRO_DISPLAY *display = NULL;          // cria uma instancia de display onde sera carregadas informações
    ALLEGRO_SAMPLE *sample = NULL;            // cria ponteiro para a memória de armazenamento de audio
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;  // cria ponteiro pra esperar da instancia display um evento(ação) de tecla 
    ALLEGRO_EVENT ev;                         // não lembro mas é necessário haha depois eu descubro

    // verificadores, caso negativo o programa é encerrado pra evitar problemas de hardware e memória
    printf("\nadicionar verificadores de inicio das fontes e desenhos\n");
    if (!al_init()) {                                                   // Caso a biblioteca principal do allegro não seja iniciada
        fprintf(stderr, "Falha ao inicializar o Allegro.\n");           // corretamente o software encerra
        return -1;
    }

    display = al_create_display(850, 850);  // Chama a instancia criada para a janela e carrega a informação de seu tamanho


    if (!display) {                                                     // Caso o display não seja iniciado corretamente 
        fprintf(stderr, "Falha ao criar a janela.\n");                  // fecha o software
        return -1;
    }

    // Define as cores dos objetos
    ALLEGRO_COLOR cor_teste = al_map_rgb(255, 51, 153);                 // aqui eu chamo uma função do allegro5 "ALLEGRO_COLOR" e defino uma variável para 
    ALLEGRO_COLOR cor_background = al_map_rgb(1, 46, 64);               // armazenar o valor criado pela biblioteca, que nesse caso é um RGB, o "al_map_rgb"
    ALLEGRO_COLOR cor_background_teste = al_map_rgb(100, 46, 200);      // é uma função que retornará um valor que gera uma cor sendo o primeiro R(red),
    ALLEGRO_COLOR cor_linha = al_map_rgb(242, 227, 213);                // G(green) e B(blue), quanto maior o valor mais da cor terá na cor final
    ALLEGRO_COLOR cor_circulo = al_map_rgb(140, 31, 40);
    ALLEGRO_COLOR cor_retangulo = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR cor_texto = al_map_rgb(10, 200, 10);
    ALLEGRO_COLOR cor_texto_menu_inferior = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR cor_texto_circulo = al_map_rgb(140, 31, 40);
    ALLEGRO_COLOR cor_texto_retangulo = al_map_rgb(0, 0, 0);
    // coloquei uma variavel diferente pros numeros pra se caso queira mudar a cor

    // Importa e carrega o arquivo da fonte
    ALLEGRO_FONT *fonte = al_load_font("./assets/Pixelify.ttf", 65, 0);                            // chama a função de armazenamento e criação de ponteiro para
    ALLEGRO_FONT *fonte_inicio = al_load_font("./assets/Pixelify.ttf", 85, 0);                     // uma fonte, armazena em uma variável e chama a função de 
    ALLEGRO_FONT *fonte_creditos_instrucoes = al_load_font("./assets/Pixelify.ttf", 35, 0);        // carregamento "al_load_font", passa como parâmetro uma pasta
    ALLEGRO_FONT *fonte_inicio_menu_inferior = al_load_font("./assets/Pixelify.ttf", 20, 0);       // do jogo, a assets que criei para armazenar arquivos de imagem
                                                                                                   // sons, fontes e afins, da o caminho da fonte, o tamanho desejado
                                                                                                   // e a flag 0 que até o momento não entendi bem pra que serve

    // Implementos de audio
    //sample = al_load_sample("assets/Reprise - Class Act - ANBR Adrian Berenguer.ogg");             // segue a mesma lógica dos anteriores mas pro áudio 
    //al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP, NULL);

    // Define caracteristicas dos objetos do jogo
    int espessura_sharp = 5;            // o sharp é #
    int espessura_circulo = 4;
    int espessura_retangulo = 4;
    int valor_forca = 1;
    int lugar_limpeza = 1;
    int contador = 0;

    int circulos_um = 2;
    int circulos_dois = 2;
    int circulos_tres = 2;

    int retangulos_um = 2;
    int retangulos_dois = 2;
    int retangulos_tres = 2;

    int valor_forca_espaco_um = 0;
    int valor_forca_espaco_dois = 0;
    int valor_forca_espaco_tres = 0;
    int valor_forca_espaco_quatro = 0;
    int valor_forca_espaco_cinco = 0;
    int valor_forca_espaco_seis = 0;
    int valor_forca_espaco_sete = 0;
    int valor_forca_espaco_oito = 0;
    int valor_forca_espaco_nove = 0;

    int figura = 0;
    int posicao = 0;
    int posicao_um = 0;
    int posicao_dois = 0;
    int posicao_tres = 0;
    int posicao_quatro = 0;
    int posicao_cinco = 0;
    int posicao_seis = 0;
    int posicao_sete = 0;
    int posicao_oito = 0;
    int posicao_nove = 0;
    
 
    // Limpa a tela toda para a cor de fundo
    al_clear_to_color(cor_background);


    // Cria evento de leitura de tecla
    event_queue = al_create_event_queue();

    al_install_keyboard();
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // 
    void entrada() {
        al_flip_display();
        al_draw_text(fonte_inicio, cor_texto, 10, 10, 0, " ");
        al_rest(1.0);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "_______");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "________");
        al_flip_display();

        al_rest(0.1);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "G______");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "_______S");
        al_flip_display();
        
        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GO_____");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "______RS");
        al_flip_display();

        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GOB____");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "_____ERS");
        al_flip_display();

        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GOBB___");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "____LERS");
        al_flip_display();

        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GOBBL__");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "___BLERS");
        al_flip_display();

        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GOBBLE_");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "__BBLERS");
        al_flip_display();

        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GOBBLET");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "_OBBLERS");
        al_flip_display();

        al_rest(0.1);
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 260, 200, 0, "GOBBLET");
        al_draw_text(fonte_inicio, cor_texto, 230, 300, 0, "GOBBLERS");
        al_flip_display();

        al_rest(0.4);
        al_draw_text(fonte_inicio_menu_inferior, cor_texto, 360, 470, 0, "1  -     Jogar");
        al_flip_display();
        al_rest(0.2);
        al_draw_text(fonte_inicio_menu_inferior, cor_texto, 360, 500, 0, "2 -    Instruções");
        al_flip_display();
        al_rest(0.2);
        al_draw_text(fonte_inicio_menu_inferior, cor_texto, 360, 530, 0, "3 -    Créditos");
        al_flip_display();
        al_rest(0.2);
        al_draw_text(fonte_inicio_menu_inferior, cor_texto, 380, 750, 0, "esc -  Sair");
        al_flip_display();
    }
    entrada();   // Chama a função void acima para carregar na tela de jogo as primeiras informações  

    // Desenha o tabuleiro
    void sharp() {
        al_draw_line(300, 250, 300, 750, cor_linha, espessura_sharp); // verticar esquerda
        al_draw_line(600, 250, 600, 750, cor_linha, espessura_sharp); // vertical direita
        al_draw_line(200, 350, 700, 350, cor_linha, espessura_sharp); // horizontal superior
        al_draw_line(200, 650, 700, 650, cor_linha, espessura_sharp); // horizontal inferior

        al_draw_text(fonte, cor_texto, 370, 5, 0, "1");
        al_draw_text(fonte, cor_texto, 410, 5, 0, "2");
        al_draw_text(fonte, cor_texto, 460, 5, 0, "3");
        al_draw_text(fonte, cor_texto, 360, 50, 0, "4");
        al_draw_text(fonte, cor_texto, 410, 50, 0, "5");
        al_draw_text(fonte, cor_texto, 460, 50, 0, "6");
        al_draw_text(fonte, cor_texto, 360, 95, 0, "7");
        al_draw_text(fonte, cor_texto, 410, 95, 0, "8");
        al_draw_text(fonte, cor_texto, 460, 95, 0, "9");
        al_draw_text(fonte_inicio_menu_inferior, cor_texto, 270, 170, 0, "Digite a posição e o número da peça");
        al_flip_display();
    }

    // DESENHA OS CIRCULOS QUANDO CHAMADOS
    // superior esquerdo
    void circ_sup_esq(valor_forca) {                                                 // quando o desenho for chamado ele irá receber um valor como
        switch (valor_forca) {                                                       // parâmetro que será utilizado para selecionar o switch que 
            case 1:                                                                  // corresponde a força chamada
                al_draw_circle(200, 250, 30, cor_circulo, espessura_circulo);        // Chama o desenhador do allegro5, passa a localização no plano
                al_draw_text(fonte, cor_circulo, 185, 210, 0, "1");                  // cartesiano, passa as caracteristicas e atualiza a tela no final   
                al_flip_display();    
                break;

            case 2:
                al_draw_circle(200, 250, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 210, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(200, 250, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 210, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // meio esquerdo
    void circ_meio_esq(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(200, 490, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 450, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(200, 490, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 450, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(200, 490, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 450, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }

    
    // inferior esquerdo
    void circ_inf_esq(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(200, 750, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 710, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(200, 750, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 710, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(200, 750, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 185, 710, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }

    
    // superior meio
    void circ_sup_meio(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(450, 250, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 210, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(450, 250, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 210, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(450, 250, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 210, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // meio meio
    void circ_meio_meio(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(450, 490, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 450, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(450, 490, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 450, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(450, 490, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 450, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }

   
    // inferior meio
    void circ_inf_meio(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(450, 750, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 710, 0, "1");
                al_flip_display();            
                break;

            case 2:
                al_draw_circle(450, 750, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 710, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(450, 750, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 430, 710, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // superior direito
    void circ_sup_dir(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(700, 250, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 210, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(700, 250, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 210, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(700, 250, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 210, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }

    
    // meio direito
    void circ_meio_dir(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(700, 490, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 450, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(700, 490, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 450, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(700, 490, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 450, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // inferior direito
    void circ_inf_dir(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_circle(700, 750, 30, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 710, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_circle(700, 750, 40, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 710, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_circle(700, 750, 50, cor_circulo, espessura_circulo);
                al_draw_text(fonte, cor_circulo, 680, 710, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }
    // FIM CIRCULOS



    // DESENHA OS RETANGULOS
    // superior esquerdo
    void rect_sup_esq(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(170, 220, 230, 280, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 210, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(160, 210, 240, 290, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 210, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(150, 200, 250, 300, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 210, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // meio esquerdo
    void rect_meio_esq(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(170, 460, 230, 520, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 450, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(160, 450, 240, 530, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 450, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(150, 440, 250, 540, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 450, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // inferior esquerdo
    void rect_inf_esq(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(170, 720, 230, 780, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 710, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(160, 710, 240, 790, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 710, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(150, 700, 250, 800, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 185, 710, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // superior meio
    void rect_sup_meio(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(420, 220, 480, 280, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 210, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(410, 210, 490, 290, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 210, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(400, 200, 500, 300, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 210, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // meio meio
    void rect_meio_meio(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(420, 460, 480, 520, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 450, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(410, 450, 490, 530, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 450, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(400, 440, 500, 540, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 450, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // inferior meio
    void rect_inf_meio(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(420, 720, 480, 780, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 710, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(410, 710, 490, 790, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 710, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(400, 700, 500, 800, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 430, 710, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // superior direito
    void rect_sup_dir(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(670, 220, 730, 280, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 210, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(660, 210, 740, 290, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 210, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(650, 200, 750, 300, cor_retangulo, espessura_retangulo);            
                al_draw_text(fonte, cor_retangulo, 680, 210, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // meio direito
    void rect_meio_dir(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(670, 460, 730, 520, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 450, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(660, 450, 740, 530, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 450, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(650, 440, 750, 540, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 450, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }


    // inferior direito
    void rect_inf_dir(valor_forca) {
        switch (valor_forca) {
            case 1:
                al_draw_rectangle(670, 720, 730, 780, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 710, 0, "1");
                al_flip_display();
                break;

            case 2:
                al_draw_rectangle(660, 710, 740, 790, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 710, 0, "2");
                al_flip_display();
                break;

            case 3:
                al_draw_rectangle(650, 700, 750, 800, cor_retangulo, espessura_retangulo);
                al_draw_text(fonte, cor_retangulo, 680, 710, 0, "3");
                al_flip_display();
                break;

            default:
                break;
        }
    }
    // FIM RETANGULOS


    void limpa_opcao_invalida() {                                        // quando selecionada uma opção incorreta aparece na tela que a opção 
        al_draw_filled_rectangle(275, 810, 650, 840, cor_background);    // é inválida, isso limpa a escrita posteriormente para não atrapalhar
    }                                                                    // o restante do jogo 
    

    // Limpa os lugares para serem substituidos por novas figuras    
    void limpa(lugar_limpeza) {
        switch (lugar_limpeza) {
            case 1: //limpa_superior_esquerdo
                al_draw_filled_rectangle(140, 190, 280, 310, cor_background);
                al_flip_display();
                break;

            case 2: //limpa superior meio
                al_draw_filled_rectangle(340, 190, 560, 310, cor_background);
                al_flip_display();
                break;

            case 3: //limpa superior direito
                al_draw_filled_rectangle(640, 190, 780, 310, cor_background);
                al_flip_display();
                break;


            
            case 4: //limpa meio esquerdo
                al_draw_filled_rectangle(140, 390, 280, 600, cor_background);
                al_flip_display();
                break;

            case 5: //limpa meio_meio
                al_draw_filled_rectangle(340, 390, 560, 600, cor_background);
                al_flip_display();
                break;

            case 6: //limpa meio direito
                al_draw_filled_rectangle(640, 390, 780, 600, cor_background);
                al_flip_display();
                break;


            case 7: //limpa inferior esquerdo
                al_draw_filled_rectangle(140, 690, 280, 850, cor_background);
                al_flip_display();
                break;

            case 8: //limpa meio inferior
                al_draw_filled_rectangle(340, 690, 560, 850, cor_background);
                al_flip_display();
                break;

            case 9: //limpa inferior direito
                al_draw_filled_rectangle(640, 690, 780, 850, cor_background);
                al_flip_display();
                break;

            default:
                break;
        }
    }

    // Comportamentos da janela(display)
    al_flip_display();
    void instrucoes() {
        al_clear_to_color(cor_background);
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 280, 0, "Cada jogador iniciará a partida com duas");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 320, 0, "peças de cada uma das 3 forças, sendo a");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 360, 0, "força forte(3) e a força fraca(1), as peças");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 400, 0, "com números menores podem ser substituidas");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 440, 0, "por peças com numeros mais altos que ela, o");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 480, 0, "jogador tem 6 peças totais ao inicio de jogo.");
        al_flip_display();
        while(1) {
            al_wait_for_event(event_queue, &ev);

            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        printf("A tecla 'ESC' foi pressionada.\n");
                        al_clear_to_color(cor_background);
                        al_draw_text(fonte_inicio, cor_texto, 240, 350, 0, "Aguarde");
                        al_draw_text(fonte_inicio, cor_texto, 200, 430, 0, "voltando...");
                        al_flip_display();
                        entrada();
                        return 0;

                    default:
                        break;
                }
            }
        }
    }

    void creditos() {
        al_clear_to_color(cor_background);
        al_draw_text(fonte_inicio, cor_texto, 70, 150, 0, "Desenvolvedores");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 150, 320, 0, "- Emerson Alexandre Tieppo Junior");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 150, 400, 0, "- Lucas Hiroshi Okamoto Catuyama");       
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 150, 480, 0, "- Misael Castro Correia");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 20, 670, 0, "Discentes de graduação no curso de bacharel");
        al_draw_text(fonte_creditos_instrucoes, cor_texto, 40, 700, 0, "em engenharia de software do 1° semestre.");
        al_draw_text(fonte_inicio_menu_inferior, cor_texto, 350, 800, 0, "esc - voltar");
        al_flip_display();

        while(1) {
            al_wait_for_event(event_queue, &ev);
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        printf("A tecla 'ESC' foi pressionada.\n");
                        al_clear_to_color(cor_background);
                        al_draw_text(fonte_inicio, cor_texto, 240, 350, 0, "Aguarde");
                        al_draw_text(fonte_inicio, cor_texto, 200, 430, 0, "voltando...");
                        al_flip_display();
                        entrada();
                        return 0;

                    default:
                        break;
                }
            }
        }
    }

    void le_valor_forca() {
        while(1) {
            al_wait_for_event(event_queue, &ev);
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_1:
                        valor_forca = 1;
                        return 0;
                        break;

                    case ALLEGRO_KEY_2:
                        valor_forca = 2;
                        return 0;
                        break;

                    case ALLEGRO_KEY_3:
                        valor_forca = 3;
                        return 0;
                        break;

                    default:
                        break;
                }
            }
        }
    }

    void verifica_vitoria_dois(){
        if (posicao_um == posicao_dois && posicao_dois == posicao_tres && posicao_um != 0 && posicao_dois != 0 && posicao_tres != 0) {
            if (posicao_um == 1 && posicao_dois == 1 && posicao_tres == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_quatro == posicao_cinco && posicao_cinco == posicao_seis && posicao_quatro != 0 && posicao_cinco != 0 && posicao_seis != 0) {
            if (posicao_quatro == 1 && posicao_cinco == 1 && posicao_seis == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_sete == posicao_oito && posicao_oito == posicao_nove && posicao_sete != 0 && posicao_oito != 0 && posicao_nove != 0) {
            if (posicao_sete == 1 && posicao_oito == 1 && posicao_nove == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_um == posicao_cinco && posicao_cinco == posicao_nove && posicao_um != 0 && posicao_cinco != 0 && posicao_nove != 0) {
            if (posicao_um == 1 && posicao_cinco == 1 && posicao_nove == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_tres == posicao_cinco && posicao_cinco == posicao_sete && posicao_tres != 0 && posicao_cinco != 0 && posicao_sete != 0) {
            if (posicao_tres == 1 && posicao_cinco == 1 && posicao_sete == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_um == posicao_quatro && posicao_quatro == posicao_sete && posicao_um != 0 && posicao_quatro != 0 && posicao_sete != 0) {
            if (posicao_um == 1 && posicao_quatro == 1 && posicao_sete == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_dois == posicao_cinco && posicao_cinco == posicao_oito && posicao_dois != 0 && posicao_cinco != 0 && posicao_oito != 0) {
            if (posicao_dois == 1 && posicao_cinco == 1 && posicao_oito == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;

        } else if (posicao_tres == posicao_seis && posicao_seis == posicao_nove && posicao_tres != 0 && posicao_seis != 0 && posicao_nove != 0) {
            if (posicao_tres == 1 && posicao_seis == 1 && posicao_nove == 1) {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "Jogador do circulo venceu!");
            } else {
                al_draw_text(fonte, cor_texto, 5, 750, 0, "jogador do retangulo venceu!");
            }
            return 0;
        }
    }

    void verifica_vitoria(posicao, figura) {
        switch (posicao) {
            case 1:
                posicao_um = figura;
                verifica_vitoria_dois();
                return 0;
                break;
            
            case 2:
                posicao_dois = figura;
                verifica_vitoria_dois();
                return 0;
                break;
            
            case 3:
                posicao_tres = figura;
                verifica_vitoria_dois();
                return 0;
                break;

            case 4:
                posicao_quatro = figura;
                verifica_vitoria_dois();
                return 0;
                break;

            case 5:
                posicao_cinco = figura;
                verifica_vitoria_dois();
                return 0;
                break;

            case 6:
                posicao_seis = figura;
                verifica_vitoria_dois();
                return 0;
                break;

            case 7:
                posicao_sete = figura;
                verifica_vitoria_dois();
                return 0;
                break;

            case 8:
                posicao_oito = figura;
                verifica_vitoria_dois();
                return 0;
                break;

            case 9:
                posicao_nove = figura;
                verifica_vitoria_dois();
                return 0;
                break;
            
            default:
                break;
        }
    }

    void jogar() {
        al_clear_to_color(cor_background);
        sharp();
        al_flip_display();

        while(1) {
            if (circulos_um == 0 && circulos_dois == 0 && circulos_tres == 0 && retangulos_um == 0 && retangulos_dois == 0 && retangulos_tres == 0) {
                al_draw_filled_rectangle(1, 1, 849, 195, cor_background);
                al_draw_text(fonte, cor_texto, 110, 70, 0, "Acabaram as peças");
            }
            al_flip_display();
            al_wait_for_event(event_queue, &ev);
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        printf("A tecla 'ESC' foi pressionada.\n");
                        al_clear_to_color(cor_background);
                        al_draw_text(fonte_inicio, cor_texto, 240, 350, 0, "Aguarde");
                        al_draw_text(fonte_inicio, cor_texto, 200, 430, 0, "voltando...");
                        al_flip_display();
                        entrada();
                        return 0;

                    case ALLEGRO_KEY_1:
                        lugar_limpeza = 1;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_um) {
                            if (valor_forca == 1 && circulos_um > 0){
                                valor_forca_espaco_um = valor_forca;
                                posicao = 1;
                                figura = 1;
                                limpa(lugar_limpeza);
                                circ_sup_esq(valor_forca);
                                contador ++;
                                verifica_vitoria(posicao, figura);
                                circulos_um --;
                                limpa_opcao_invalida();

                            } else if (valor_forca == 2 && circulos_dois > 0){
                                valor_forca_espaco_um = valor_forca;
                                posicao = 1;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                limpa(lugar_limpeza);
                                circ_sup_esq(valor_forca);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();

                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                valor_forca_espaco_um = valor_forca;
                                posicao = 1;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                limpa(lugar_limpeza);
                                circ_sup_esq(valor_forca);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();

                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }

                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_um) {
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 1;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_um = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_esq(valor_forca);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 1;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_um = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_esq(valor_forca);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 1;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_um = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_esq(valor_forca);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_1");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;

                    case ALLEGRO_KEY_2:
                        lugar_limpeza = 2;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_dois) { 
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 2;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_dois = valor_forca;
                                limpa(lugar_limpeza);
                                circ_sup_meio(valor_forca);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 2;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_dois = valor_forca;
                                limpa(lugar_limpeza);
                                circ_sup_meio(valor_forca);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 2;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_dois = valor_forca;
                                limpa(lugar_limpeza);
                                circ_sup_meio(valor_forca);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_dois) {
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 2;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_dois = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_meio(valor_forca);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 2;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_dois = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_meio(valor_forca);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 2;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_dois = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_meio(valor_forca);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_2");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;


                    case ALLEGRO_KEY_3:
                        lugar_limpeza = 3;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_tres) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 3;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_tres = valor_forca;
                                limpa(lugar_limpeza);
                                circ_sup_dir(valor_forca);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 3;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_tres = valor_forca;
                                limpa(lugar_limpeza);
                                circ_sup_dir(valor_forca);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 3;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_tres = valor_forca;
                                limpa(lugar_limpeza);
                                circ_sup_dir(valor_forca);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_tres) {
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 3;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_tres = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_dir(valor_forca);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 3;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_tres = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_dir(valor_forca);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 3;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_tres = valor_forca;
                                limpa(lugar_limpeza);
                                rect_sup_dir(valor_forca);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_3");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;


                    case ALLEGRO_KEY_4:
                        lugar_limpeza = 4;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_quatro) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 4;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_quatro = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_esq(valor_forca);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 4;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_quatro = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_esq(valor_forca);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 4;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_quatro = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_esq(valor_forca);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_quatro) {
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 4;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_quatro = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_esq(valor_forca);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 4;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_quatro = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_esq(valor_forca);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 4;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_quatro = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_esq(valor_forca);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_4");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;


                    case ALLEGRO_KEY_5:
                        lugar_limpeza = 5;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_cinco) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 5;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_cinco = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_meio(valor_forca);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 5;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_cinco = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_meio(valor_forca);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 5;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_cinco = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_meio(valor_forca);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_cinco) {
                            valor_forca_espaco_cinco = valor_forca;
                            
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 5;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_um = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_meio(valor_forca);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 5;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_cinco = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_meio(valor_forca);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 5;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_cinco = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_meio(valor_forca);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_5");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;


                    case ALLEGRO_KEY_6:
                        lugar_limpeza = 6;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_seis) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 6;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_seis = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_dir(valor_forca);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 6;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_seis = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_dir(valor_forca);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 6;
                                figura = 1;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_seis = valor_forca;
                                limpa(lugar_limpeza);
                                circ_meio_dir(valor_forca);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_seis) {
                            valor_forca_espaco_seis = valor_forca;
                            
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 6;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_um = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_dir(valor_forca);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 6;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_seis = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_dir(valor_forca);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 6;
                                figura = 2;
                                verifica_vitoria(posicao, figura);
                                valor_forca_espaco_seis = valor_forca;
                                limpa(lugar_limpeza);
                                rect_meio_dir(valor_forca);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_6");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;

                    case ALLEGRO_KEY_7:
                        lugar_limpeza = 7;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_sete) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 7;
                                figura = 1;
                                valor_forca_espaco_sete = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_esq(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 7;
                                figura = 1;
                                valor_forca_espaco_sete = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_esq(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 7;
                                figura = 1;
                                valor_forca_espaco_sete = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_esq(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_sete) {
                            valor_forca_espaco_sete = valor_forca;
                            
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 7;
                                figura = 2;
                                valor_forca_espaco_sete = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_esq(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 7;
                                figura = 2;
                                valor_forca_espaco_sete = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_esq(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 7;
                                figura = 2;
                                valor_forca_espaco_sete = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_esq(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_7");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;


                    case ALLEGRO_KEY_8:
                        lugar_limpeza = 8;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_oito) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 8;
                                figura = 1;
                                valor_forca_espaco_oito = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_meio(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 8;
                                figura = 1;
                                valor_forca_espaco_oito = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_meio(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 8;
                                figura = 1;
                                valor_forca_espaco_oito = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_meio(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_oito) {
                            valor_forca_espaco_oito = valor_forca;
                            
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 8;
                                figura = 2;
                                valor_forca_espaco_oito = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_meio(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 8;
                                figura = 2;
                                valor_forca_espaco_oito = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_meio(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 8;
                                figura = 2;
                                valor_forca_espaco_oito = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_meio(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar seção allegro_key_8");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;

                        
                    case ALLEGRO_KEY_9:
                        lugar_limpeza = 9;
                        le_valor_forca();
                        if (contador % 2 == 0 && valor_forca > valor_forca_espaco_nove) {
                            if (valor_forca == 1 && circulos_um > 0){
                                posicao = 9;
                                figura = 1;
                                valor_forca_espaco_nove = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_dir(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && circulos_dois > 0){
                                posicao = 9;
                                figura = 1;
                                valor_forca_espaco_nove = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_dir(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && circulos_tres > 0) {
                                posicao = 9;
                                figura = 1;
                                valor_forca_espaco_nove = valor_forca;
                                limpa(lugar_limpeza);
                                circ_inf_dir(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                circulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else if (contador % 2 == 1 && valor_forca > valor_forca_espaco_nove) {
                            valor_forca_espaco_nove = valor_forca;
                            
                            if (valor_forca == 1 && retangulos_um > 0){
                                posicao = 9;
                                figura = 2;
                                valor_forca_espaco_nove = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_dir(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_um --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 2 && retangulos_dois > 0){
                                posicao = 9;
                                figura = 2;
                                valor_forca_espaco_nove = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_dir(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_dois --;
                                limpa_opcao_invalida();
                                
                            } else if (valor_forca == 3 && retangulos_tres > 0) {
                                posicao = 9;
                                figura = 2;
                                valor_forca_espaco_nove = valor_forca;
                                limpa(lugar_limpeza);
                                rect_inf_dir(valor_forca);
                                verifica_vitoria(posicao, figura);
                                contador ++;
                                retangulos_tres --;
                                limpa_opcao_invalida();
                                
                            } else {
                                al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                            }
                            
                        } else {
                            printf("Possivel erro no calculo de par e impar: allegro_key_9");
                            al_draw_text(fonte_inicio_menu_inferior, cor_texto, 275, 810, 0, "opção invalida, tente outra força");
                        }
                        al_flip_display();
                        break;
                      
                    default:
                        break;
                }
            }
        }
    }

    while(1) {
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_1:
                    jogar();
                    break;

                case ALLEGRO_KEY_2:
                    instrucoes();
                    break;

                case ALLEGRO_KEY_3:
                    creditos();
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    printf("A tecla 'ESC' foi pressionada.\n");
                    return 0;

                default:
                    break;
            }
        }
    }

    


    // sharp();
    // circ_sup_esq(valor_forca);
    // lugar_limpeza = 1;
    // limpa(lugar_limpeza);
    al_rest(100.0); // Tempo em que a janela fica aberta
    printf("\nalterar tempo em que a janela fica aberta\n");

    // Finaliza, fecha e limpa memoria
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
