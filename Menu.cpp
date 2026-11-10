
#include <iostream>
#include <algorithm>

#include "Menu.h"
#include <string>
#include "Ente.h"

namespace IlhaDosPiratas {
        Menu::Menu() :
            telaAtual(MENU_PRINCIPAL),
            faseSelecionada(1),
            quantidadeJogadores(1)
        {
            fonte.loadFromFile("assets/fonte.ttf");

            titulo.setFont(fonte);
            titulo.setCharacterSize(55);
            titulo.setFillColor(sf::Color(235, 203, 131));
            titulo.setString("Definir");

            if (!texturaFundo.loadFromFile("assets/menu.png")) {
                std::cout << "Erro ao carregar fundo do menu!" << std::endl;
            }
            else {
                fundo.setTexture(texturaFundo);

                sf::Vector2u tamanho = texturaFundo.getSize();

                fundo.setScale(
                    1920.f / tamanho.x,
                    1080.f / tamanho.y
                );
            }

        }

        Menu::~Menu()
        {
        }

        void Menu::adicionarBotao(
            const std::string& texto,
            Acao acao,
            float x,
            float y
        )
        {
            Botao botao;

            botao.acao = acao;

            botao.forma.setSize(sf::Vector2f(360.f, 65.f));
            botao.forma.setPosition(x, y);
            botao.forma.setFillColor(sf::Color::Transparent);

            botao.texto.setFont(fonte);
            botao.texto.setString(texto);
            botao.texto.setCharacterSize(27);
            botao.texto.setFillColor(sf::Color(235, 203, 131));

            sf::FloatRect limites = botao.texto.getLocalBounds();

            botao.texto.setOrigin(
                limites.left + limites.width / 2.f,
                limites.top + limites.height / 2.f
            );

            botao.texto.setPosition(
                x + 180.f,
                y + 32.5f
            );

            botoes.push_back(botao);
        }

        void Menu::criarBotoes(sf::RenderWindow& janela)
        {
            botoes.clear();

            float centroX = janela.getSize().x / 2.f;
            float centroY = janela.getSize().y / 2.f;

            if (telaAtual == MENU_PRINCIPAL) {

                titulo.setString("Ilha dos Piratas");

                adicionarBotao(
                    "NOVO JOGO",
                    NOVO_JOGO,
                    centroX - 180.f,
                    centroY - 60.f
                );

                adicionarBotao(
                    "CONTINUAR",
                    CONTINUAR,
                    centroX - 180.f,
                    centroY + 0.f
                );

                adicionarBotao(
                    "RANK",
                    RANK,
                    centroX - 180.f,
                    centroY + 60.f
                );

                adicionarBotao(
                    "SAIR",
                    SAIR,
                    centroX - 180.f,
                    centroY + 110.f
                );
            }

            else if (telaAtual == SELECIONAR_FASE) {

                titulo.setString("SELECIONE A FASE");

                adicionarBotao(
                    "FASE 1",
                    FASE_1,
                    centroX - 180.f,
                    centroY - 60.f
                );

                adicionarBotao(
                    "FASE 2",
                    FASE_2,
                    centroX - 180.f,
                    centroY + 20.f
                );

                adicionarBotao(
                    "VOLTAR",
                    VOLTAR,
                    centroX - 180.f,
                    centroY + 100.f
                );
            }

            else if (telaAtual == SELECIONAR_JOGADORES) {

                titulo.setString("QUANTIDADE DE JOGADORES");

                adicionarBotao(
                    "1 JOGADOR",
                    UM_JOGADOR,
                    centroX - 180.f,
                    centroY - 60.f
                );

                adicionarBotao(
                    "2 JOGADORES",
                    DOIS_JOGADORES,
                    centroX - 180.f,
                    centroY + 20.f
                );

                adicionarBotao(
                    "VOLTAR",
                    VOLTAR,
                    centroX - 180.f,
                    centroY + 100.f
                );
            }
            else if (telaAtual == TELA_RANKING) {

                titulo.setString("RANKING");

                adicionarBotao(
                    "VOLTAR",
                    VOLTAR,
                    centroX - 180.f,
                    centroY + 180.f
                );
            }

            sf::FloatRect limites = titulo.getLocalBounds();

            titulo.setOrigin(
                limites.left + limites.width / 2.f,
                limites.top + limites.height / 2.f
            );

            titulo.setPosition(centroX, centroY - 200.f);
        }

        void Menu::desenhar(sf::RenderWindow& janela)
        {
            janela.draw(fundo);
            criarBotoes(janela);
            janela.draw(titulo);

            if (telaAtual == TELA_RANKING) {
                desenharRanking(janela);
            }

            for (unsigned int i = 0; i < botoes.size(); i++) {
                janela.draw(botoes[i].forma);
                janela.draw(botoes[i].texto);
            }
        }

        Menu::Resultado Menu::tratarEventos(
            sf::Event evento,
            sf::RenderWindow& janela
        )
        {
            if (evento.type != sf::Event::MouseButtonPressed ||
                evento.mouseButton.button != sf::Mouse::Left) {
                return NENHUM;
            }

            criarBotoes(janela);

            sf::Vector2f mouse = janela.mapPixelToCoords(
                sf::Vector2i(
                    evento.mouseButton.x,
                    evento.mouseButton.y
                )
            );

            for (unsigned int i = 0; i < botoes.size(); i++) {

                if (!botoes[i].forma.getGlobalBounds().contains(mouse))
                    continue;

                switch (botoes[i].acao) {

               case NOVO_JOGO:
                   telaAtual = SELECIONAR_FASE;
                   break;

               case CONTINUAR:
                   return CONTINUAR_PARTIDA;

               case RANK:
                   telaAtual = TELA_RANKING;
                   break;

               case SAIR:
                   return SAIR_DO_JOGO;

               case FASE_1:
                   faseSelecionada = 1;
                   telaAtual = SELECIONAR_JOGADORES;
                   break;

               case FASE_2:
                   faseSelecionada = 2;
                   telaAtual = SELECIONAR_JOGADORES;
                   break;

               case UM_JOGADOR:
                   quantidadeJogadores = 1;
                   return INICIAR_PARTIDA;

               case DOIS_JOGADORES:
                   quantidadeJogadores = 2;
                   return INICIAR_PARTIDA;

               case VOLTAR:

                   if (telaAtual == SELECIONAR_FASE)
                       telaAtual = MENU_PRINCIPAL;

                   else if (telaAtual == SELECIONAR_JOGADORES)
                       telaAtual = SELECIONAR_FASE;

                   else if (telaAtual == TELA_RANKING)
                       telaAtual = MENU_PRINCIPAL;

                   break;
               }

               return NENHUM;
           }

           return NENHUM;
       }

       int Menu::getFaseSelecionada() const
        {
           return faseSelecionada;
       }

       int Menu::getQuantidadeJogadores() const
       {
           return quantidadeJogadores;
       }
       void Menu::desenharRanking(sf::RenderWindow& janela)
       {
           
           std::sort(
               pontuacoes.begin(),
               pontuacoes.end(),
               [](const std::pair<std::string, int>& a,
                   const std::pair<std::string, int>& b) {
                       return a.second > b.second;
               }
           );

           sf::Text texto;
           texto.setFont(fonte);
           texto.setCharacterSize(30);
           texto.setFillColor(sf::Color(235, 203, 131));

           std::string resultado = "";

           int limite = std::min(5, (int)pontuacoes.size());

           for (int i = 0; i < limite; i++) {
               resultado += std::to_string(i + 1) + "� - ";
               resultado += pontuacoes[i].first + " : ";
               resultado += std::to_string(pontuacoes[i].second);
               resultado += "\n";
           }

           if (pontuacoes.empty()) {
               resultado = "Nenhuma pontuacao registrada";
           }

           texto.setString(resultado);

           sf::FloatRect limites = texto.getLocalBounds();

           texto.setOrigin(
               limites.left + limites.width / 2.f,
               limites.top + limites.height / 2.f
           );

           texto.setPosition(
               janela.getSize().x / 2.f,
               janela.getSize().y / 2.f
           );

           janela.draw(texto);
       }
}
