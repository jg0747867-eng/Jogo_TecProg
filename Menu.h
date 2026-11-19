
#pragma once

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <utility>
#include "Ente.h"

/*
 * Ressalto novamente meu agradecimento aos colegas do PETECO,
 * Raphael Geraldine e Marco Vendramin, e também ao Burda,
 * visto que nossa implementação foi baseada na deles.
 *
 * Vide:
 * https://github.com/Raphael-Geraldine/O-Equilibrio-da-Forca/blob/master/include/Lista.h
 * e vídeo 8 da playlist Tutorial Jogo SFML.
 */


namespace Tripulacao_Amaldicoada {

        class Menu {
        private:

            enum Tela {
                MENU_PRINCIPAL,
                SELECIONAR_FASE,
                SELECIONAR_JOGADORES,
                TELA_RANKING,
                MENU_PAUSA
            };

            enum Acao {
                NOVO_JOGO,
                CONTINUAR,
                RANK,
                SAIR,
                FASE_1,
                FASE_2,
                UM_JOGADOR,
                DOIS_JOGADORES,
                VOLTAR,
                REINICIAR,
                VOLTAR_MENU
            };

            struct Botao {
                sf::RectangleShape forma;
                sf::Text texto;
                Acao acao;
            };

            Tela telaAtual;

            sf::Font fonte;
            sf::Text titulo;

            sf::Texture texturaFundo;
            sf::Sprite fundo;

            std::vector<Botao> botoes;

            std::vector<std::pair<std::string, int>> pontuacoes;

            int faseSelecionada;
            int quantidadeJogadores;

            void criarBotoes(sf::RenderWindow& janela);
            void adicionarBotao(
                const std::string& texto,
                Acao acao,
                float x,
                float y
            );

        public:

            enum Resultado {
                NENHUM,
                INICIAR_PARTIDA,
                CONTINUAR_PARTIDA,
                RETOMAR_PARTIDA,
                REINICIAR_FASE,
                VOLTAR_MENU_PRINCIPAL,
                SAIR_DO_JOGO
            };

            Menu();
            ~Menu();

            Resultado tratarEventos(
                sf::Event evento,
                sf::RenderWindow& janela
            );

            void desenhar(sf::RenderWindow& janela);

            int getFaseSelecionada() const;
            int getQuantidadeJogadores() const;
            void desenharRanking(sf::RenderWindow& janela);

            void abrirPausa();
            void abrirMenuPrincipal();
            void desenharPausa(sf::RenderWindow& janela);
        };
}

#endif
