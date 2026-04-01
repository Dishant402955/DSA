class Solution
{
public:
    using u32 = uint32_t;

    [[nodiscard]] auto survivedRobotsHealths(
        std::vector<int>& pos_,
        std::vector<int>& hp_,
        std::string& dir) noexcept
    {
        auto& pos = reinterpret_cast<std::vector<u32>&>(pos_);
        auto& hp = reinterpret_cast<std::vector<u32>&>(hp_);
        const u32 n = static_cast<u32>(pos_.size());

        // Assemble the indices in their natural ascending order
        static u32 indices[100000];
        std::iota(indices, indices + n, 0u);

        // Arrange said indices according
        // to the positions they reference
        std::ranges::sort(
            indices,
            indices + n,
            std::less{},
            [&](auto i) { return pos[i]; });

        // nr: the present tally of surviving
        // automatons proceeding rightward
        for (u32 i = 0, nr = 0; i != n; ++i)
        {
            u32 right = indices[i];
            bool in = dir[right] == 'L';
            if (in && nr)
            {
                // We have encountered a contrarian soul advancing
                // leftward, whilst at least one stalwart persists
                // in moving right. Thus, a most inevitable duel
                // must be conducted. Let it be known: the fallen
                // shall have their vitality reduced to naught.
                u32 left = indices[nr - 1];
                if (hp[right] < hp[left])
                {
                    // The rightward challenger is bested
                    hp[right] = 0;
                    --hp[left];
                }
                else if (hp[right] > hp[left])
                {
                    // The leftward defender is undone: permit
                    // this fellow another engagement forthwith
                    --i;
                    hp[left] = 0;
                    --hp[right];
                    --nr;
                }
                else
                {
                    // A most equitable demise befalls both parties
                    --nr;
                    hp[right] = 0;
                    hp[left] = 0;
                }
            }
            else
            {
                // Admit the current automaton into
                // the ranks, should it be worthy
                indices[nr] = indices[i];
                nr += !in;
            }
        }

        // The original ordering of positions remains undisturbed
        // we shall merely gather those whose vitality yet
        // endures into the position array, sparing ourselves
        // needless allocation
        u32 alive = 0;
        for (u32 h : hp)
        {
            pos[alive] = h;
            alive += !!h;
        }

        pos.resize(alive);

        return pos_;
    }
};                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        // Collect surviving robots
        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};
