import math


def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

class Core:
    def __init__(self, core_id, x, y, layer):
        self.core_id = core_id
        self.x = x
        self.y = y
        self.layer = layer
        self.assigned_tsv = None
        self.is_tsv = False
    
    def assign_tsv(self, tsv):
        self.assigned_tsv = tsv

class TSV:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Topology:
    def __init__(self, rows, columns, layers, tsv_positions):
        self.rows = rows
        self.columns = columns
        self.layers = layers
        self.cores = []
        self.tsvs = []
        self.tsv_positions = tsv_positions
        self.precompute_config = []
        self.validate_minimum_tsv_count()
        self.generate_topology()
        self.validate_tsv_placement()

    def validate_minimum_tsv_count(self):
        if len(self.tsv_positions) < 2:
            print("Error: At least 2 TSVs are required. Provided:", len(self.tsv_positions))
            exit()

    def generate_topology(self):
        core_id = 0
        for layer in range(self.layers):
            for i in range(self.rows):
                for j in range(self.columns):
                    core = Core(core_id, i, j, layer)
                    self.cores.append(core)
                    core_id += 1

        for position in self.tsv_positions:
            tsv = TSV(position[0], position[1])
            self.tsvs.append(tsv)

    def validate_tsv_placement(self):
        for i, tsv1 in enumerate(self.tsvs):
            for j, tsv2 in enumerate(self.tsvs):
                if i != j:
                    distance = manhattan_distance(tsv1.x, tsv1.y, tsv2.x, tsv2.y)
                    if distance < 2:
                        print(f"Error: Invalid placement of TSVs at ({tsv1.x}, {tsv1.y}) and ({tsv2.x}, {tsv2.y}). Distance: {distance}")
                        exit()

    def assign_tsvs_to_routers(self):
        for core in self.cores:
            min_distance = math.inf
            closest_tsv = None
            
            for tsv in self.tsvs:
                if (core.x, core.y) == (tsv.x, tsv.y):
                    core.is_tsv = True

                distance = manhattan_distance(core.x, core.y, tsv.x, tsv.y)
                if distance < min_distance:
                    min_distance = distance
                    closest_tsv = tsv
            
            core.assign_tsv(closest_tsv)

    def get_core_tsv_mappings(self):
        mappings = []
        for core in self.cores:
            is_tsv = 1 if core.is_tsv else 0
            mapping = [
                core.core_id, 
                (core.layer, core.x, core.y), 
                is_tsv, 
                (core.assigned_tsv.x, core.assigned_tsv.y)
            ]
            mappings.append(mapping)
        return mappings

    def compute_precompute_config(self):
        self.precompute_config = self.get_core_tsv_mappings()

    def print_mappings(self):
        for mapping in self.precompute_config:
            print(mapping)


rows = 3
columns = 4
layers = 2
tsv_positions = [(0, 0), (1, 1), (2, 2)] 

topology = Topology(rows, columns, layers, tsv_positions)
topology.assign_tsvs_to_routers()
topology.compute_precompute_config()
topology.print_mappings()


print("Precompute Config Array:")
print(topology.precompute_config)