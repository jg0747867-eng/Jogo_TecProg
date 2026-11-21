
#pragma once

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <utility>
#include "Ente.h"

/*
 * Ressalto novamente meu agradecimento ao influencer do canal,
 * Terminal Root, onde o menu foi inspirado
 * Video:
 * https://youtu.be/h8-Q4eu3Qt4?si=6dOCI3o2VRJbqBUI
 * 
 */


namespace Tripulacao_Amaldicoada {

        class Menu {
        private:

            enum Tela{
                MENU_PRINCIPAL,
                DIGITAR_NOME,
                SELECIONAR_FASE,
                SELECIONAR_JOGADORES,
                TELA_RANKING,
                TELA_RESULTADO,
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
                VOLTAR_MENU,
                CONFIRMAR_NOME,
                CONFIRMAR_RESULTADO
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

            std::string nomeJogador;
            std::string nomeFinal;

            int faseSelecionada;
            int quantidadeJogadores;
            int pontuacaoFinal;

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

            std::string getNomeJogador() const;

            void mostrarResultado(int pontos);

            void desenharResultado(sf::RenderWindow& janela);

            void desenhar(sf::RenderWindow& janela);

            int getFaseSelecionada() const;
            int getQuantidadeJogadores() const;
            void desenharRanking(sf::RenderWindow& janela);

            void abrirPausa();
            void abrirMenuPrincipal();
            void desenharPausa(sf::RenderWindow& janela);

            void registrarResultado(int pontos);
            void abrirResultado();
        };
}

#endif
