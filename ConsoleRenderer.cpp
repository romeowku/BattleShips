#include "ConsoleRenderer.h"

void ConsoleRenderer::printOptionField(GameField& field, int x, int y, bool player) const
{      
    const Cell& cell = field.getCell(x, y);
    switch (cell.getStatus())
    {
        case Cell::CellStatus::Unknown:
            std::cout << "⚪️ ";
            break;
        case Cell::CellStatus::Empty:
            std::cout << "🔵 ";
            break;
        case Cell::CellStatus::Ship:
            if (cell.getShip() != nullptr) 
            {
                Ship* ship = cell.getShip();
                int segmentIndex = cell.getShipIndex();

                switch (ship->getSegment(segmentIndex))
                {
                    case Ship::SegmentState::Whole:
                        (player) ? std::cout << "⬛️ " : std::cout << "⚪️ ";
                        break;
                    case Ship::SegmentState::Damaged:
                        std::cout << "🟨 ";
                        break;
                    case Ship::SegmentState::Destroyed:
                        std::cout << "🟥 ";
                        break;
                }
            }
            break;
    }
}

void ConsoleRenderer::printField(GameField& field, bool player) const
{
    std::vector<std::string> emojis = {"0️⃣","1️⃣", "2️⃣", "3️⃣", "4️⃣", "5️⃣", "6️⃣", "7️⃣", "8️⃣", "9️⃣", "1️⃣"};
    std::cout << "   ";
    for (int x = 0; x < field.getWidth(); x++) {
        std::cout << emojis[x] << "  ";
    }
    std::cout << '\n';

    for (int y = 0; y < field.getHeight(); y++)
    {
        std::cout << emojis[y] << "  "; 

        for (int x = 0; x < field.getWidth(); x++)
        {      
            (player) ? printOptionField(field, x, y, true) : printOptionField(field, x, y, false);
        }
        std::cout << '\n';
    }
}

void ConsoleRenderer::printMessage(const std::string& message) { std::cout << message << "\n"; }

void ConsoleRenderer::printNumShips(ShipManager& shipManager) 
{  
    std::cout << "--------- Your number of ships: " << shipManager.getNumShips() << " ---------\n";
    std::cout << "------ The ships will be deployed next (sizes): ";
    for (int i = 0; i < shipManager.getNumShips(); i++) 
    {
        std::cout << "[" << shipManager.getShip(i).getLength() << "] ";
    }
    std::cout << " ------\n\n";
}