
#pragma once

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <utility>
#include "Ente.h"

namespace Trabalhojogo {

        class Menu {
        private:

            enum Tela {
                MENU_PRINCIPAL,
                SELECIONAR_FASE,
                SELECIONAR_JOGADORES,
                TELA_RANKING
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
                VOLTAR
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
        };
}

#endif
