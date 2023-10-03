#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");


    // PONTOS DE DESTAQUE
    // Criei o código pensando na organização que facilite a manutenção, por isso tem seções de código
    // geralmente a seção é identificada pelos comentarios acima e as funções de cada linha ao lado direito
    // os printf utilizei para pontos que podem ser melhorados pois aparecem só no terminal, mas fiquem a 
    // vontade pra implementar novas ideias

    // Utilizei o allegro5 como biblioteca GUI





    // Inicia e armazena as bibliotecas do allegro5
    al_init(); // inicia a biblioteca padrao do allegro
    al_init_primitives_addon(); // contem draw circle e rectangle
    al_init_ttf_addon(); // contem load do ttf pras fontes
    al_init_font_addon(); // contm a biblioteca de escrita pra fonte
    
    // cria ponteiro para uma janela(display)
    ALLEGRO_DISPLAY* display = NULL; 


    // verificadores, caso negativo o programa é encerrado pra evitar problemas
    printf("\nadicionar verificadores de inicio das fontes e desenhos\n");
    if (!al_init()) { 
        fprintf(stderr, "Falha ao inicializar o Allegro.\n");
        return -1;
    }

    display = al_create_display(850, 850);
    if (!display) {
        fprintf(stderr, "Falha ao criar a janela.\n");
        return -1;
    }



    // Define as cores dos objetos
    al_clear_to_color(al_map_rgb(1, 46, 64));
    
    ALLEGRO_COLOR cor_linha = al_map_rgb(242, 227, 213);
    ALLEGRO_COLOR cor_circulo = al_map_rgb(140, 31, 40);
    ALLEGRO_COLOR cor_retangulo = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR cor_texto = al_map_rgb(10, 200, 10);
    ALLEGRO_COLOR cor_texto_circulo = al_map_rgb(140, 31, 40);
    ALLEGRO_COLOR cor_texto_retangulo = al_map_rgb(0, 0, 0);
    // coloquei uma variavel diferente pros numeros pra se caso queira mudar a cor

    
    // Importa e carrega o arquivo da fonte  
    ALLEGRO_FONT *fonte = al_load_font("./assets/inter.ttf", 65, 0);
    


    // Desenha o tabuleiro
    al_draw_line(300, 250, 300, 750, cor_linha, 5);
    al_draw_line(600, 250, 600, 750, cor_linha, 5);
    al_draw_line(200, 350, 700, 350, cor_linha, 5);
    al_draw_line(200, 650, 700, 650, cor_linha, 5);


    // DESENHA OS CIRCULOS
    //superior esquerdo
    al_draw_circle(200, 250, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 210, 0, "1");
    al_draw_circle(200, 250, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 210, 0, "2");
    al_draw_circle(200, 250, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 210, 0, "3");

    //meio esquerdo
    al_draw_circle(200, 490, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 450, 0, "1");
    al_draw_circle(200, 490, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 450, 0, "2");
    al_draw_circle(200, 490, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 450, 0, "3");

    //inferior esquerdo
    al_draw_circle(200, 750, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 710, 0, "1");
    al_draw_circle(200, 750, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 710, 0, "2");
    al_draw_circle(200, 750, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 185, 710, 0, "3");

    //superior meio
    al_draw_circle(450, 250, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 210, 0, "1");
    al_draw_circle(450, 250, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 210, 0, "2");
    al_draw_circle(450, 250, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 210, 0, "3");

    //meio meio
    al_draw_circle(450, 490, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 450, 0, "1");
    al_draw_circle(450, 490, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 450, 0, "2");
    al_draw_circle(450, 490, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 450, 0, "3");

    //inferior meio
    al_draw_circle(450, 750, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 710, 0, "1");
    al_draw_circle(450, 750, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 710, 0, "2");
    al_draw_circle(450, 750, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 430, 710, 0, "3");

    //superior direito
    al_draw_circle(700, 250, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 210, 0, "1");
    al_draw_circle(700, 250, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 210, 0, "2");
    al_draw_circle(700, 250, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 210, 0, "3");

    //meio direito
    al_draw_circle(700, 490, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 450, 0, "1");
    al_draw_circle(700, 490, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 450, 0, "2");
    al_draw_circle(700, 490, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 450, 0, "3");

    //inferior direito
    al_draw_circle(700, 750, 30, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 710, 0, "1");
    al_draw_circle(700, 750, 40, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 710, 0, "2");
    al_draw_circle(700, 750, 50, cor_circulo, 4);
    al_draw_text(fonte, cor_circulo, 680, 710, 0, "3");
    // FIM CIRCULOS


    // DESENHA OS RETANGULOS
    //superior esquerdo
    al_draw_rectangle(150, 200, 250, 300, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 210, 0, "1");
    al_draw_rectangle(160, 210, 240, 290, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 210, 0, "2");
    al_draw_rectangle(170, 220, 230, 280, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 210, 0, "3");

    //meio esquerdo
    al_draw_rectangle(150, 440, 250, 540, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 450, 0, "1");
    al_draw_rectangle(160, 450, 240, 530, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 450, 0, "2");
    al_draw_rectangle(170, 460, 230, 520, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 450, 0, "3");

    //inferior esquerdo
    al_draw_rectangle(150, 700, 250, 800, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 710, 0, "1");
    al_draw_rectangle(160, 710, 240, 790, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 710, 0, "2");
    al_draw_rectangle(170, 720, 230, 780, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 185, 710, 0, "3");

    //superior meio
    al_draw_rectangle(400, 200, 500, 300, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 210, 0, "1");
    al_draw_rectangle(410, 210, 490, 290, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 210, 0, "2");
    al_draw_rectangle(420, 220, 480, 280, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 210, 0, "3");

    //meio meio
    al_draw_rectangle(400, 440, 500, 540, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 450, 0, "1");
    al_draw_rectangle(410, 450, 490, 530, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 450, 0, "2");
    al_draw_rectangle(420, 460, 480, 520, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 450, 0, "3");

    //inferior meio
    al_draw_rectangle(400, 700, 500, 800, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 710, 0, "1");
    al_draw_rectangle(410, 710, 490, 790, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 710, 0, "2");
    al_draw_rectangle(420, 720, 480, 780, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 430, 710, 0, "3");
    

    //superior direito
    al_draw_rectangle(650, 200, 750, 300, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 210, 0, "1");
    al_draw_rectangle(660, 210, 740, 290, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 210, 0, "2");
    al_draw_rectangle(670, 220, 730, 280, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 210, 0, "3");


    //meio direito
    al_draw_rectangle(650, 440, 750, 540, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 450, 0, "1");
    al_draw_rectangle(660, 450, 740, 530, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 450, 0, "2");
    al_draw_rectangle(670, 460, 730, 520, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 450, 0, "3");

    //inferior direito
    al_draw_rectangle(650, 700, 750, 800, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 710, 0, "1");
    al_draw_rectangle(660, 710, 740, 790, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 710, 0, "2");
    al_draw_rectangle(670, 720, 730, 780, cor_retangulo, 4);
    al_draw_text(fonte, cor_retangulo, 680, 710, 0, "3");
    // FIM RETANGULOS



    // Comportamentos da janela(display)
    al_flip_display();
    al_rest(100.0); // Tempo em que a janela fica aberta
    printf("\nalterar tempo em que a janela fica aberta\n");

    // Finaliza, fecha e limpa memoria
    al_destroy_display(display);

    return 0;
}
